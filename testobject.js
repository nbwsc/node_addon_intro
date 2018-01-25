// test.js
const addon = require("./build/Release/object");

const obj1 = addon("hello");
const obj2 = addon("world");
console.log(obj1.msg, obj2.msg);
// Prints: 'hello world'
