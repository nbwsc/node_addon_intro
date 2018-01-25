// test.js
const addon = require("./build/Release/function");

const fn = addon();
console.log(fn());
// Prints: 'hello world'
