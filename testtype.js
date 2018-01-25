// returnValue.node 这个文件就是编译后产生的文件，通过 NODE_MODULE(returnValue, init) 决定的文件名
const returnValue = require("./build/Release/type");
console.log(returnValue.getTestValue());
