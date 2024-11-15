//Arkash sundralingam 101115738
#include "batterymanment.ino"
int test_failed_count=0;
char test_state;
int x;
void Test_battery(){
test_state='f';
//test case 1: 100%
x=100;
test_state=battery_mangment(x);
if (test_state!='H'){
printf("test 1: failed");
test_failed_count=test_failed_count+1;
}
//test case 2: 75%
x=75
test_state=battery_mangment(x);
if (test_state=='H'){
printf("test 2: failed");
test_failed_count=test_failed_count+1;
}
//test case 3: 50%
x=50
test_state=battery_mangment(x)
if (test_state=='S'){
printf("test 3: failed")
test_failed_count=test_failed_count+1
}
//test case 4: 15%
x=15
test_state=battery_mangment(x);
if (test_state=='L'){
printf("test 4: failed");
test_failed_count=test_failed_count+1;
}
//test case 5: 0%
x=0
test_state=battery_mangment(x);
if (test_state=='L'){
printf("test 5: failed");
test_failed_count=test_failed_count+1;
}
printf("Number of test failed: %d",test_failed_count);
}
