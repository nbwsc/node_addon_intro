const getArguments = require("./build/Release/js-cpp");

console.log(
    getArguments(
        2,
        3,
        "Hello Arguments",
        [1, 2, 3],
        {
            a: 10,
            b: 100,
            c: [23, 22, "我是33"],
            d: { m: "我是22", n: "我是23" }
        },
        true,
        null,
        undefined,
        function myFunction(...args) {
            console.log("I am Function!");
            console.log(...args);
            console.log("I am Function!");
        }
    )
);
/**
 * 
I am not Object
I am not Boolean
I am not Array
I am not String
I am not Function
I am not Null
I am not Undefined
Hello Arguments
3, 1.000000 2.000000
10   100
3, 23.000000 22.000000
我是33
我是22
我是23
Flag: 1
I am Function!
10 100
I am Function!
5
 */
