const addon1 = require('bindings')('addon1.node');
const addon2 = require('bindings')('addon2.node');

const cat = new addon1.Cat("mr-cat",1);
console.log('cat age: ',cat.age()); // 'world'
console.log('cat fightVal: ',cat.fightval()); // 'world'


const dog = new addon2.Dog("mr-dog",2);
console.log('dog age: ',dog.age()); 
console.log('dog fightVal: ',dog.fightval()); 