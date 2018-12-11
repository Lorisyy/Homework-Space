#智能蛇（Smart snake)
## By 宿永烨 18342107
Written by Su Yongye ,SYSU,ID:18342107,11/Dec/2018
## Algorithms and applications
In this scene of the requirement .We needed to declare three things:food,move and position.
### Food 
By using  <time.h>,we can easily allocate food on the map,as long as the location is not fullfilled [1]or surrounded [2]by the snake while the length of the snake is approaching the celing of the given map.

[1] seems easy to understand because the body of the snake cannot be overlapped by the food that was born randomly.

[2] is a little complex concept ,but imagine that imagine the final scene of the game,the whole screen is filled with your snake's body ,there is only one way to keep your snake alive,that is,to make your food do not appear in the map and let the snake follow its tail continously.From this I knew that one of the basic rule is:
>if(snakelen==12*12-1)

>NOT produce food






### Move
From the GIF image
![Snake](images/snake.gif)
 we can get a conclusion that the basic moving algorithm is :

*As soon as you have already got your food,move backwards to the opposite side of your current direction,if possible,move along the wall is a smart choice so your body is spread at the whole map.*


In this way can we set our snake to a longevity snake!



##Position 
We can use vector to represente our snake's direction,but how about the distance between walls and your head?  
Here goes my baby snake's way to avoid getting hurt!

We only need to slove this question at the very beginning of it,that is,how to avoid the head moving onto the wall?

This problem can be solved by calculating the distance between your snake's head and three wall(**why three?** **Good question!**).

Why three ?
Because your head is limited to the three direction :Keep the current direction,turn left and turn right!

This is all my thoughts!!!

\>w<


---------------------
## 12/Dec/2018 Update
  
## What if our purpose is to limit the snake to a specific number n?  
(n >= minLength && n < 12*12-1)

The key is to LIMIT to n,
so on the way you have to avoid eating food.

`IF snakeLen==n`


`Move up to the food and turn left,turn right*2 and turn left `

This is to Half surround the food.

## About greedy algorithm
There is a problem that we'd better no use it:
The Greedy Algorithm is always finding the best solution in a specific question or part,the Local optimum IS OF COURSE NOT simply equal to GLOBAL optimum.