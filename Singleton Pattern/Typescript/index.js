"use strict";
class Singleton {
    constructor() { }
    static getInstance() {
        if (!Singleton.instance) {
            console.log("Running Singleton Constructor. Creating an instance.");
            Singleton.instance = new Singleton();
        }
        return Singleton.instance;
    }
}
const clientCode = () => {
    const obj1 = Singleton.getInstance();
    const obj2 = Singleton.getInstance();
    if (obj1 === obj2)
        console.log("Singleton works, both variables contain the same instance.");
    else
        console.log("Singleton failed, variables contain different instances.");
};
clientCode();
