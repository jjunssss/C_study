#include <stdio.h>

/*  카탈로그 항목 출력  */
void catalog(const char *name, const char *species, int teeth, int age)
{
    printf("%s는 %s종이며, 이빨이 %i개고 %i살입니다\n", name, species, teeth, age);
}

/*  수족관 수조의 설명 출력*/
void label(const char *name, const char *species, int teeth, int age)
{
    printf("이름: %s\n종: %s\n이빨 수: %i\n나이: %i\n", name, species, teeth, age);

}
int main()
    {
        catalog("스내피", "피라냐", 69, 4);
        label("스내피", "피라냐", 69, 4);
        return 0;
    }

