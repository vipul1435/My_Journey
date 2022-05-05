console.log("HELLO VIPUL");
//It is used for print any think thing like cin and print fuction

console.log(inp);
/*------------***********-----------*/
// Data types and variabl
/* undefined , null bollean string symbol number and objecet*/
 var a = "vipul"
 a = 8
 let b= "this is vipul"
 const pi = 3.14        //value can  not chnage;
 console.log(pi)
 a = 7
 console.log(a)
// it is case sensitive languge

// addition 
var sum = 10+20
console.log(sum); console.log(sum++)
// output is 30
sum-- //decrement operator 
console.log(sum)    //output 29
sum++           //increment operator
console.log(sum) //output 30

////// all operator like + - * / % work same as c or c++;
 

// canctenation in string 
// we can add two or more string using + operator
var m = " this is  "+ " java script cousre"
console. log(m)
m +=m // add string it self and operator work likr other languages like c or c++
console. log(m)
console. log(m[2]) //access any index like c and c++;


/******************** FOR PRINT A QUATED STRING  *************/

// var d= " " this is vipul rajput" " when we try to write this then it show error 
var d = '"this is vipul"'
 //write the double coated statement in single quates
console.log(d)

/************ NOTE ***********/
// all operator work same like other c or c++
// i.e. + - < > => <= += -= same function
 
/******** STRING FUCTION ***********/
 var d = "this is my java scrpit complete code"
var len = d.length // gives the lenght of string
 console.log(len)



  /**********DEFINING FUNTION ************/
   function fun( str){          //defining fuction
       var name = "vipul"
       name+=str;
       return name      //returning the value from the fuction
   }
   console.log(fun("kumar"))    // calling a fucntin and passing value like c, c++

   function ad(a,b){
       return a+b;
   }
 console.log(ad(10,50));

   /**********  ARRAY ***********/
   var ar= [1, 3, "vip"]
   console.log(ar[1])

 // two dimwnsional 2D array
 var ad = [[1,2,3],[4,5 ,6],[5,6,7]]
//  print Array
console.log(ad)
 //acces elemet 
 console.log(ad[2][1]) //print element by index
   // ADD DATA TO ARRAY BY PUSH FUCTION
 ad.push("ADDED DATA") // IR IS USED TO ADD THE NEW DATA TO THE END OF THE ARRAY    
 console.log(ad);
// remove element from array
ad.pop(); // remove the element from the last of the array
console.log(ad);
ad.shift();        // it is used to remove the first element of the array
console.log(ad);
ad.unshift("vipul"); // it is used to add function at the starting of the array
console.log(ad) 
/***********IF ELSE CONDITION *****/
 /*if(true condition){
     statement.....
     statement.....
     statement.....
     statement.....
 }
 else {
    statement.....
    statement.....
    statement.....
    statement.....
 } */

d= 5;
var j = 5;
if(j==d) {
    console.log("EQUAL NUMBERS");
}
else {
    console.log("NUMBERS ARE NOT EQUAL");
}
/* the given given codition return eqaul while a integer can not be equl to a string.
this is because compiler first try to change string to integer and after comparison it will compare.
so it return equal*/
if(3=='3') console.log("equal")
else console.log("not equal")
 /* to avoid from this we should use strghtly comprator which is === */

if(3==='3') console.log("equal") ///it return not equal
else console.log("not equal") 

/*****NOTE ***********/
/* AND and OR operator are work same as c ,c++ which && and || repactively */
/* nested if else working same as c ++ */

/***** SWITCH STATEMENT  ***********/

d= 5;
switch(d){
    case 1: console.log("number is",d)
    break;
    case 2: console.log("number is",d);
    break;
    case 5: console.log("number is found",d);
    break;
}
//  multiple switch statment 
 d=5;
 switch(d){
     case 1:
     case 2:
         console.log("marke are low");
         break;
    case 3:
    case 4:
    case 5:
        console.log("marks are good");
        break;
 }











