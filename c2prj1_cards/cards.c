#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"

//该函数应使用 assert() 检查传入的卡牌是否具有有效值。
//特别是，其值应在 2 到 VALUE_ACE（包括这两个值）之间，
//花色应在 SPADES 到 CLUBS（包括这两个值）之间。
void assert_card_valid(card_t c) {//传入牌与花色
int cond1,cond2;
cond1=(c.value >= 2)&&(c.value <= VALUE_ACE);//2~14
cond2=(c.suit ==  SPADES )||(c.suit == CLUBS )||(c.suit ==  HEARTS)||(c.suit == DIAMONDS);
//花色 
assert(cond1 && cond2);//条件为假会立即停止执行，并抛出一个异常
}

//该函数应将传入的 hand_ranking_t(牌的组合) 枚举值转换为描述它的字符串。
const char * ranking_to_string(hand_ranking_t r) {
 switch (r){
  case  STRAIGHT_FLUSH:  return "STRAIGHT_FLUSH";
  case  FOUR_OF_A_KIND: return"FOUR_OF_A_KIND";
  case FULL_HOUSE: return"FULL_HOUSE";
  case  FLUSH: return"FLUSH";
  case  STRAIGHT: return"STRAIGHT";
  case  THREE_OF_A_KIND: return"THREE_OF_A_KIND";
  case  TWO_PAIR: return"TWO_PAIR";
  case  PAIR: return"PAIR";
  default  : return"NOTHING";
  }
}
//该函数应返回表示传入卡牌出来单调对应字符
char value_letter(card_t c) {
  char x='?';
  if ((c.value >= 2 )&&( c.value <=9)) x = '0' + c.value ;
  else {
    switch(c.value){
    case VALUE_KING : {x='K';  break;}
    case 10 : {   x='0';  break;}
    case VALUE_ACE :{ x= 'A' ;  break;}
    case VALUE_QUEEN :{x='Q' ; break;}
    case VALUE_JACK :{x='J' ; break;}
    default :break;
    }
  }
  return x ;//失败就返回  ?
}

//花色返回对应名称
char suit_letter(card_t c) {
 char x='?';
  switch(c.suit){//访问传入的结构体中花色，枚举
  case  SPADES : {x='s';  break;}
  case HEARTS : {   x='h';  break;}
  case DIAMONDS :{ x= 'd' ;  break;}
  case CLUBS :{x='c' ; break;}
  default :{ x='N'; break;}
  }
  return x;
  
}
//打印花色与牌号
void print_card(card_t c) {
//访问传入结构  传出牌的号的函数、
 char suit1= suit_letter( c);
  char value1= value_letter( c);
  printf("%c%c ",value1,suit1);
}
//创建并返回一个 card_t，其值和花色对应于传入的字母
card_t card_from_letters(char value_let, char suit_let) {
 card_t temp;
  switch(value_let){
  case 'K' : {temp.value= 13;  break;}
  case '0' : { temp.value= 10;  break;}
  case 'A' :{ temp.value= 14;  break;}
  case 'Q' :{temp.value= 12; break;}
  case 'J' :{temp.value= 11; break;}
  default :{temp.value=value_let - '0';
      break;} }

  switch(suit_let){
  case  's'  : {temp.suit =SPADES;  break;}
  case 'h' : {  temp.suit =HEARTS;  break;}
  case 'd' :{temp.suit = DIAMONDS ;  break;}
  case  'c':{temp.suit =CLUBS ; break;}
  default: {temp.suit = NUM_SUITS;  break; }}
  assert_card_valid(temp);
  return temp;
}
//c is [0,52)  唯一映射到卡牌值/花色组合
card_t card_from_num(unsigned c) {
 card_t temp;
  unsigned value = c%13 + 2;
  temp.value = value;
  
  unsigned suit = c/13;
  switch(suit){
  case  0 : {temp.suit =SPADES;  break;}
  case 1 : {  temp.suit =HEARTS;  break;}
  case 2 :{temp.suit = DIAMONDS ;  break;}
  case 3:{temp.suit =CLUBS ; break;}
  default: {temp.suit = NUM_SUITS;  break; }}
  
  sreturn temp;
