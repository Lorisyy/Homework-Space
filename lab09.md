# 洗衣机算法设计& Top-down design 
## What is top-down design???
Top-down design provides a way to solve problem,it generally starts at what you need to do first or your expectation in the end of the problem.  

Top-down is a strategie of information processing and knowledge ordering, used in a variety of fields including software, humanistic and scientific theories, and management and organization. In practice, it can be seen as a style of thinking, teaching, or leadership. 

A top-down approach (also known as stepwise design and in some cases used as a synonym of decomposition) is essentially the breaking down of a system to gain insight into its compositional sub-systems in a reverse engineering fashion. In a top-down approach an overview of the system is formulated, specifying, but not detailing, any first-level subsystems. Each subsystem is then refined in yet greater detail, sometimes in many additional subsystem levels, until the entire specification is reduced to base elements. A top-down model is often specified with the assistance of "black boxes", which makes it easier to manipulate. However, black boxes may fail to clarify elementary mechanisms or be detailed enough to realistically validate the model. Top down approach starts with the big picture. It breaks down from there into smaller segments. 

![Top-down design](images/pubu.png)

So,a top-down design is to say that one approach of design is mainly seen from the top of the problem,which looks like an operation with a GODVIEW.
## 使用伪代码表示“洗衣程序”
>洗衣程序包括以下几个步骤：  
（通电，加入洗衣液，）打开进水开关，关闭进水开关，浸泡衣服，左右滚动滚筒，打开排水开关，关闭排水开关，重复非括号内的步骤n次（视具体情况而定）。
>A：The Pseudocode of a general procedure of a washer.
 
SET RollingCOUNT = 1  
FOR RollingCOUNT = 1 to 10  
SET water_in_switch(open)
function wait(time)   
count = 0   
WHILE wait = 1s ,count < time   
count++   
END WHILE    
END fuction  

function waterIn(volumeNeeded,timeout)    
water_in_switch(open)     
current = get_water_volume()  
FOR   current=get_water_volume  () to volumeNeeded  
keep the switch open  
IF time == timeout   
stop the machine  (halt())   
END IF
END FOR  
IF time == timeout   
stop the machine (halt())   
END IF
IF　current == volumeNeeded  
water_in_switch(close)   
END IF  
END function  


function waterOut(minVolumeNeeded,timeout)    
water_out_switch(open)     
current = get_water_volume()  
FOR   current=get_water_volume  () to volumeNeeded  
keep the switch open  
END FOR  
IF　current == volumeNeeded  
water_out_switch(close)  
END IF  
END function  

main :  
FOR count = 0 to 10  
waterInIF (volumeNeeded,timeout)  
FOR countRoll = 0 to 5  
motor_run(left) 3*360°   
motor_run(stop)  
motor-run(right)  3*360°    
END FOR  
waterOut(minVolumeNeeded,timeout)  
END FOR  


