#include <node.h>
#include <v8.h>
#include <iostream>

using namespace v8;
using namespace std;

void GetArgument(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    // 参数长度判断
    if (args.Length() < 2) {
        isolate->ThrowException(Exception::TypeError(
            String::NewFromUtf8(isolate, "Wrong number of arguments")));
        return;
    }

    // 参数类型判断
    if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
        //抛出错误
        isolate->ThrowException(Exception::TypeError(
            String::NewFromUtf8(isolate, "argumnets must be number")));
    }

    if (!args[0]->IsObject()) {
        printf("I am not Object\n");
    }

    if (!args[0]->IsBoolean()) {
        printf("I am not Boolean\n");
    }

    if (!args[0]->IsArray()) {
        printf("I am not Array\n");
    }

    if (!args[0]->IsString()) {
        printf("I am not String\n");
    }

    if (!args[0]->IsFunction()) {
        printf("I am not Function\n");
    }

    if (!args[0]->IsNull()) {
        printf("I am not Null\n");
    }

    if (!args[0]->IsUndefined()) {
        printf("I am not Undefined\n");
    }

    // js Number 类型转换成 v8 Number 类型
    Local<Number> value1 = Local<Number>::Cast(args[0]);
    Local<Number> value2 = Local<Number>::Cast(args[1]);
    double value = value1->NumberValue() + value2->NumberValue();

    // js String 类型转换成 v8 String 类型
    Local<String> str = Local<String>::Cast(args[2]);
    String::Utf8Value utfValue(str);
    cout<<string(*utfValue)<<endl;

    // js Array 类型转换成 v8 Array 类型
    Local<Array> input_array = Local<Array>::Cast(args[3]);
    printf("%d, %f %f\n", input_array->Length(), input_array->Get(0)->NumberValue(), input_array->Get(1)->NumberValue());

    // js Object 类型转换成 v8 Object 类型
    Local<Object> obj = Local<Object>::Cast(args[4]);

    // 根据 key 获取对象中的值
    Local<Value> a = obj->Get(String::NewFromUtf8(isolate, "a"));
    Local<Value> b = obj->Get(String::NewFromUtf8(isolate, "b"));

    // js Array 类型转换成 v8 Array 类型
    Local<Array> c = Local<Array>::Cast(obj->Get(String::NewFromUtf8(isolate, "c")));
    cout<<a->NumberValue()<<"   "<<b->NumberValue()<<endl;
    printf("%d, %f %f\n", c->Length(), c->Get(0)->NumberValue(), c->Get(1)->NumberValue());

    // js String 类型转换成 v8 String 类型
    Local<String> cString = Local<String>::Cast(c->Get(2));
    String::Utf8Value utfValueD(cString);
    cout<<string(*utfValueD)<<endl;

    // 根据 key 获取对象中的值
    Local<Object> d = Local<Object>::Cast(obj->Get(String::NewFromUtf8(isolate, "d")));
    Local<String> dString1 = Local<String>::Cast(d->Get(String::NewFromUtf8(isolate, "m")));
    String::Utf8Value utfValued1(dString1);
    cout<<string(*utfValued1)<<endl;

    // 根据 key 获取对象中的值
    Local<String> dString2 = Local<String>::Cast(d->Get(String::NewFromUtf8(isolate, "n")));
    String::Utf8Value utfValued2(dString2);
    cout<<string(*utfValued2)<<endl;

    // js Booelan 类型转换成 v8 Boolean 类型
    Local<Boolean> FlagTrue = Local<Boolean>::Cast(args[5]);
    cout<<"Flag: "<<FlagTrue->BooleanValue()<<endl;

    // js Function 类型转换成 v8 Function 类型
    Local<Function> cb = Local<Function>::Cast(args[8]);
    const unsigned argc = 2;
    Local<Value> argv[2];
    argv[0] = a;
    argv[1] = b;
    cb->Call(Null(isolate), argc, argv);

    args.GetReturnValue().Set(value);
}

void Init(Local <Object> exports, Local <Object> module) {
    NODE_SET_METHOD(module, "exports", GetArgument);
}

NODE_MODULE(argumentss, Init)