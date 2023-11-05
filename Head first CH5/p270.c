#include<stdio.h>

struct exercise {
    const char *description;
    float duration;
};

struct meal {
    const char *ingredients;
    float weight;
};

struct preferences {
    struct meal food;
    struct exercise exercise;
};

struct fish {
    const char *name;
    const char *species;
    int teeth;
    int age;
    struct preferences care;
};

void label(struct fish a)
{
    printf("이름: %s\n품종: %s\n이빨 수: %i\n나이: %i\n", a.name, a.species, a.teeth, a.age);
    printf("%2.2f파운드의 %s를 먹이고 %2.2f시간 동안 %s하게 하세요\n");
}

int main(){
    struct fish snappy = {"스내피", "피라냐", 69, 4, {{"고기",0.2},{"거품 수족관에서 수영",7.5}}};
}

