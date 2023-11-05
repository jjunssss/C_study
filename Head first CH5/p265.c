#include <stdio.h>
#include <stdlib.h>

void catalog(struct fish f)
{
    printf("%s는 %s종이며, 이빨이 %i개고 %i살 입니다.\n", f.name, f.species, f.teeth, f.age);
}

int main()
{
    struct fish snappy = {"스내피", "피라냐", 69, 4};
    catalog(snappy);
    /* 아직은 label() 함수를 호출하지 않습니다 */
    return 0;
}