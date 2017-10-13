# W-Lang
A simple interpreted and written language, targeted for beginners who want to learn about the stack.  
Made in early in the morning at HackBCA 2016 by Henry Wildermuth, although it was not his team's project.

## Installation
Download the language.cpp file from the repo.  
Build it using your favorite C++ compiler.  
Run it!  Run with 2 or more arguments to see a help message.

## Info
W-Lang is both an interpreter and a written language, which means that you can use it just by running the executable, or write your code in a file and run it there.
W-Lang uses a completely stack based interpreter. All data is stored as doubles, and if an unrecognized phrase (something that's not a keyword or a number) is typed, a zero will be added to the stack.  
All whitespace is interchangeable, meaning you can switch out spaces, tabs, or newlines in your code.  
Typing any number will add it to the top of the stack. Then, use keyword to manipulate and display the stack.  
All of the keywords that change/combine two values will combine them into one variable on the stack.  They also all effect from the top (most recent) part of the stack.  
Comments are also available with `/* ... */`. The `/*` and `*/` **_must_** be preceded and followed by some form of whitespace.

## Keywords
| Keyword| Use |
| :----: | :-: |
| `add` or `+`  | addition |
| `sub` or `-`  | subtraction |
| `mult` or `*` | multiplication |
| `div` or `/`  | division |
| `exp`, `pow` or `^`  | exponentiate |
| `sqrt`     | square root |
| `reset`     | empty stack |
| `dup`     | duplicate: copy top of stack |
| `rot`     | rotate: move thing in third to the top |
| `swap`     | switch positions of the top two things |
| `print`     | print the top of the stack |
| `printStack`     | print entire stack |
| `drop`     | remove top of stack |
| `end`, `exit`, `quit` or `q`    | ends a program |
| `/* ... */`     | comment |
| `e` | adds the mathematical constant e to the stack |
| `pi` | adds the mathematical constant pi to the stack |

## Examples
In order to do pythag:
```
3 4 /* enter the numbers you want to the stack, in this case I use 3 and 4. */
dup mult /* square first number */
swap dup mult /* square second number */
add sqrt /* add and take square root */
print
end
```

In order to calculate the dot product of two vectors (where Vx is 3, Vy is 4, Wx is 5 and Wy is 6)
```
3 4 5 6
mult
rot
mult
add
print
end
```
