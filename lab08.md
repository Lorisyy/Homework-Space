# 宙斯大战小猪佩奇游戏设计 18342107 宿永烨
## 游戏策划与简单玩法介绍
### Setting:
Recently, a pig named Peppa Pig invaded people's mind, everyone is talking about that pig, which annoyed Zues，who is the God of the Gods.
So the most powerfu God has decided to clear those foolish and childish pigs from the world.
### Gameplay:
Because Zues is a God,he has an unlimited power of lightning and he is invicible,the Peppa Pig is weak,but their number is huge,one lightning can clear one Peppa Pig if and only if the lightning touched the pig.The pig will reborn randomly in an area every two seconds.So you,maybe I can call you Zues NOW,have infinitely many pigs to fight with, good luck!
### Game Sprites
Player : Zeus(You can control it with your keyboard and mouse),has unlimited health as well as lightnings(Bullets).
Sprites : Peppa Pig,which can reborn every two seconds,but the pig is weak.
Bonus ： When an enemy is slain , there will be a signal to show you have slain an emery Peppa Pig.
Here is a picture to show the scene of the game.![Game](images/Gameshow.png)
## Gamesheet.
![Gamesheet](images/Gamesheet.png)
## Gaming Design & Class Responsibility Collaborations:
### CRC(Class Responsibility Collaborations) Cards:

  |Object Name| Zues(Player)  |Peppa Pig|Lightning
  |-|-|-|-|

  Attributes |Invicible,Unlimited power|Weak and Unmovable|Bullet
  -|-|-|-  
  Collaborator|Peppa Pig,Lightning|Signal of Boom,Lighting|Zues->Peppa Pig 
  Events & Actions|Controller:Mouse & Keyboard|reborn every two seconds|Unlimited

 