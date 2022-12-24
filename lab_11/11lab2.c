#include <stdio.h>
#include <assert.h>

int ascii_to_int(int symbol){
    if (symbol == 48){
        return 0;
    }
    else if (symbol == 49){
        return 1;
    }
    else if (symbol == 50){
        return 2;
    }
    else if (symbol == 51){
        return 3;
    }
    else if (symbol == 52){
        return 4;
    }
    else if (symbol == 53){
        return 5;
    }
    else if (symbol == 54){
        return 6;
    }
    else if (symbol == 55){
        return 7;
    }
}

void print_binary(int count, int array[50]){
    for (int k = 0; k < count; ++k){
        switch (array[k]) {
        	case 0: printf("0 "); break;
        	case 1: printf("1 "); break;
        	case 2: printf("10 "); break;
        	case 3: printf("11 "); break;
        	case 4: printf("100 "); break;
        	case 5: printf("101 "); break;
        	case 6: printf("110 "); break;
        	case 7: printf("111 "); break;
        }
    }
    printf("\n");
}


void test_ascii_to_int(){
    assert(ascii_to_int(48) == 0);
    assert(ascii_to_int(49) == 1);
    assert(ascii_to_int(50) == 2);
    assert(ascii_to_int(51) == 3);
    assert(ascii_to_int(52) == 4);
    assert(ascii_to_int(53) == 5);
    assert(ascii_to_int(54) == 6);
    assert(ascii_to_int(55) == 7);
}

int main(){
    test_ascii_to_int();

    int state = 1, count = 0;
    int symbol;

    while((symbol = getchar()) != '*'){
        int array[50];
        switch (state) {
            case 1:
                if (symbol >= '0' && symbol <= '7'){
                    array[count] = ascii_to_int(symbol);
                    count += 1;
                    state = 2;
                }
                else if ((symbol >= '8' && symbol <= '9') || (symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z')){
                    state = 5;
                }
                else if (symbol == ' ' || symbol == ',' || symbol == '\n' || symbol == '\t'){
                    count = 0;
                    state = 1;
                }
                break;

            case 2:
                if (symbol >= '0' && symbol <= '7'){
                    array[count] = ascii_to_int(symbol);
                    count += 1;
                    state = 2;
                }
                else if ((symbol >= '8' && symbol <= '9') || (symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z')){
                    state = 3;
                }
                else if (symbol == ' ' || symbol == ',' || symbol == '\n' || symbol == '\t'){
                    print_binary(count, array);
                    count = 0;
                    state = 4;
                }
                break;

            case 3:
                if ((symbol >= '0' && symbol <= '9') || (symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z')){
                    state = 3;
                }
                else if (symbol == ' ' || symbol == ',' || symbol == '\n' || symbol == '\t'){
                    state = 1;
                }
                break;

            case 4:
                if (symbol >= '0' && symbol <= '7'){
                    count = 0;
                    array[count] = ascii_to_int(symbol);
                    count += 1;
                    state = 2;
                }
                else if ((symbol >= '8' && symbol <= '9') || (symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z')){
                    count = 0;
                    state = 3;
                }
                else if (symbol == ' ' || symbol == ',' || symbol == '\n' || symbol == '\t'){
                    count = 0;
                    state = 1;
                }
                break;

            default:
                break;
        }
    }

    return 0;
}
