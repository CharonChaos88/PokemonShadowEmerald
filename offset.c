#include <stdio.h>
#include "include/global.h"

int main() {
    printf("ramScript: 0x%lx\n", offsetof(struct SaveBlock1, ramScript));
    printf("mysteryGift: 0x%lx\n", offsetof(struct SaveBlock1, mysteryGift));
    return 0;
}
