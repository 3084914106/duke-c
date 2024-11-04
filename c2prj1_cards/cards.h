#ifndef CARD_H
#define CARD_H
#define VALUE_ACE 14
#define VALUE_KING 13
#define VALUE_QUEEN 12
#define VALUE_JACK 11
typedef enum {
  SPADES,
  HEARTS,
  DIAMONDS,
  CLUBS,
  NUM_SUITS
} suit_t;//enum 枚举 黑 红 方 梅花 

struct card_tag {
  unsigned value;//（2、3、4、5、6、7、8、9、10、J、Q、K、A）
  suit_t suit;//表示该牌的花色
};

typedef struct card_tag card_t;//定义名字

typedef enum {
  STRAIGHT_FLUSH,//同花顺
  FOUR_OF_A_KIND,//四条
  FULL_HOUSE,//葫芦
  FLUSH,//同花
  STRAIGHT,//顺子
  THREE_OF_A_KIND,//三条
  TWO_PAIR,//两对
  PAIR,//一对
  NOTHING//无牌
} hand_ranking_t;
card_t card_from_num(unsigned c);
void assert_card_valid(card_t c);
const char * ranking_to_string(hand_ranking_t r) ;
char value_letter(card_t c);
char suit_letter(card_t c) ;
void print_card(card_t c);
card_t card_from_letters(char value_let, char suit_let);
#endif
