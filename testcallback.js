// test.js
const addon = require("./build/Release/callback");

addon(msg => {
    console.log(msg);
    // Prints: 'hello world'
});
