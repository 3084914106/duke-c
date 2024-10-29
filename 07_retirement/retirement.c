
#include<stdio.h>
#include<stdlib.h>

struct _retire_info{
  int months;
  double contribution;//每月存款
  double rate_of_return;//表示回报率（假设为“扣除通货膨胀后的”）。
};
typedef struct _retire_info retire_info;



double cal(double acc , retire_info st ){
  return acc*st.rate_of_return + st.contribution + acc;//当前的钱×回报率 + 存款 +当前的钱
}


void retirement (int startAge ,double initial , retire_info working,retire_info retired){
  double temp;//起始月 起始储蓄 
  temp= initial;//起始的钱
  for (int i=0;i<working.months ; i++,startAge++){//历遍 工作年龄+ 
    printf("Age %3d month %2d you have $%.2lf\n",startAge/12 , startAge%12, temp);//岁数年 月
    temp=cal(temp,working);//传入 当前的钱 工作ing结构体    不断更新
  }
  for (int i=0;i<retired.months;i++,startAge++){
    printf("Age %3d month %2d you have $%.2lf\n",startAge/12 , startAge%12, temp);
    temp=cal(temp,retired);
  }  
  //calculate retirement account balabce while working
  //print the formula
  //similar task to retirement
  //print out the same information
}


int main(void){
  retire_info working;//定义一个名字为working的retire_info结构结构体
  working.months=489;
  working.rate_of_return=.045/12;//换算回报率为每月多少
  working.contribution=1000;//工作时每月存入
  retire_info retired;//退休时候
  retired.months=384;
  retired.rate_of_return = .01/12;
  retired.contribution=-4000;//每月支出
  int startAge=327;//起始的的岁数
  double  initial =21345;//起始的钱
  retirement(startAge,initial,working,retired);//传入  起始岁 钱 两段结构体
  return 0;
}
