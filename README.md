# W-Lang
A simple interpreted and written language, targeted for beginners who want to learn about the stack

## Info
W-Lang uses a completely stack based interpreter. All data is stored as integers, and if an unrecognised phrase (something that's not a keyword or a number) is typed, a zero will be added to the stack.   
All whitespace is interchangable, meaning you can switch out spaces, tabs, or newlines in your code.  
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
| `exp` or `^`  | exponenetiate |
| `sqrt`     | square root |
| `reset`     | empty stack |
| `dup`     | copy top of stack |
| `rot`     | move thing in third to the top |
| `swap`     | switch positions of the top two things |
| `print`     | print the top of the stack |
| `printStack`     | print entire stack |
| `drop`     | remove top of stack |
| `end`     | ends a program |
| `/* ... */`     | comment |

## Examples
In order to do pythag, you would this code:
```
3 4 /* enter the numbers you want to the stack, in this case I use 3 and 4. */
dup mult /* square first number */
swap dup mult /* square second number */
add sqrt /* add and take square root */
print
end
```

