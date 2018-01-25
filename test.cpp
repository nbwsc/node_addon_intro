#include <node.h>
#include <v8.h>

using namespace v8;

void MyFunction(const v8::FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    args.GetReturnValue().Set(String::NewFromUtf8(isolate, "Hello World!"));
}

void Test(const v8::FunctionCallbackInfo<v8::Value>& args) {
    Isolate* isolate = args.GetIsolate();

    // Number 类型的声明
    Local<Number> retval = v8::Number::New(isolate, 1000);

    // String 类型的声明
    Local<String> str = v8::String::NewFromUtf8(isolate, "Hello World!");

    // Object 类型的声明
    Local<Object> obj = v8::Object::New(isolate);
    // 对象的赋值
    obj->Set(v8::String::NewFromUtf8(isolate, "arg1"), str);
    obj->Set(v8::String::NewFromUtf8(isolate, "arg2"), retval);

    // Function 类型的声明并赋值
    Local<FunctionTemplate> tpl = v8::FunctionTemplate::New(isolate, MyFunction);
    Local<Function> fn = tpl->GetFunction();
    // 函数名字
    fn->SetName(String::NewFromUtf8(isolate, "theFunction"));
    obj->Set(v8::String::NewFromUtf8(isolate, "arg3"), fn);

    // Boolean 类型的声明
    Local<Boolean> flag = Boolean::New(isolate, true);
    obj->Set(String::NewFromUtf8(isolate, "arg4"), flag);

    // Array 类型的声明
    Local<Array> arr = Array::New(isolate);
    // Array 赋值
    arr->Set(0, Number::New(isolate, 1));
    arr->Set(1, Number::New(isolate, 10));
    arr->Set(2, Number::New(isolate, 100));
    arr->Set(3, Number::New(isolate, 1000));
    obj->Set(String::NewFromUtf8(isolate, "arg5"), arr);

    // Undefined 类型的声明
    Local<Value> und = Undefined(isolate);
    obj->Set(String::NewFromUtf8(isolate, "arg6"), und);

    // null 类型的声明
    Local<Value> null = Null(isolate);
    obj->Set(String::NewFromUtf8(isolate, "arg7"), null);

    // 返回给 JavaScript 调用时的返回值
    args.GetReturnValue().Set(obj);
}

void init(Local <Object> exports, Local<Object> module) {
    NODE_SET_METHOD(exports, "getTestValue", Test);
}

NODE_MODULE(returnValue, init)
