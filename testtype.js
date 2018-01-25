// returnValue.node 这个文件就是编译后产生的文件，通过 NODE_MODULE(returnValue, init) 决定的文件名
const returnValue = require("./build/Release/type");
console.log(returnValue.getTestValue());
/**
 { arg1: 'Hello World!',
  arg2: 1000,
  arg3: [Function: theFunction],
  arg4: true,
  arg5: [ 1, 10, 100, 1000 ],
  arg6: undefined,
  arg7: null }
 */
