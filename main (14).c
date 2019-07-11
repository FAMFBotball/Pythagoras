#include <kipr/botball.h>
void go_forward(int m);
void turn_right(int m);
void turn_left(int m);
void backup(int m);
void arm_up();
void claw_up();
void claw_open();
void claw_close();
void claw_down();
void arm_down();
void claw_open();
void hit_wall();
void building_claw_down();
void building_claw_up();

int f = 0;




int main()
{
    create_connect();

    wait_for_light(0);
    shut_down_in(119);
    enable_servos();
    claw_open();
    msleep(400);
    claw_down();
    //arm down
    arm_down();
    msleep(600);



    //claw close to grab ambulence
    claw_close();
    msleep(400);
    arm_up();
    msleep(400);
    // turn left to hospital
    turn_left(90);
    msleep(200);
    //arm up
    arm_up();
    msleep(300);
    claw_up();
    ao();
    // to hospital
    go_forward(430);
    // turn to hospital
    turn_right(-50);
    msleep(200);
    // fire detection

    camera_open_black();
    camera_update();
    msleep (300);
    camera_update();
    msleep(300);
    if(get_object_count (0)==0)
    {
        camera_update();
        printf("No fire found!\n");
        create_stop();      
        claw_down();
        arm_down();
        claw_open();


    }
    else
    { 
        camera_update();
        printf("Found fire!\n");
        turn_right(-10);
        go_forward(150); 
        create_stop();

        arm_down();
        claw_open();
        arm_up();
        create_stop();
    }


    
    create_drive_direct(-200,-200);
    msleep(1600);
    turn_left(50);
    create_stop();
    create_drive_direct(-200,-200);
    msleep(1600);  


    turn_right(-60);
    create_stop();
    hit_wall();
    go_forward(100);
    create_stop();
    create_spin_CCW(200);
    msleep(800);
    create_stop();
    while ((get_create_rfcliff_amt() >2000)&&(get_create_lfcliff_amt() >2000))
    {
        create_drive_direct(-100,-100);
    }

    create_stop();
    
    msleep(400);
    create_spin_CCW(-200);
    msleep(710);

    create_stop();
    //building_claw_up();
    msleep(300);
   // go_forward(380);
   // building_claw_down();
    msleep(300);
   // claw_close();
    msleep(300);
   // claw_up();
    msleep(300);
   // create_drive_direct(-200,-200);
    msleep(500);
   // create_spin_CCW(200);
    msleep(500);
   // arm_down();

    disable_servos();
    camera_close();
    create_disconnect();
    ao();

    return 0;
}

void go_forward(int m)
{
    set_create_distance(0);
    while (get_create_distance()<( m))
    { 
        create_drive_direct(200,200);
    }
}
void claw_open()
{
    int f= 1800;
    while (f> 1000)
    {
        set_servo_position(2,f);
        msleep(100);
        f=f -50;
    }
}

void turn_right(int m)
{
    set_create_total_angle(0);
    while (get_create_total_angle()> m)
    {
        create_drive_direct(200,0);
    }
    create_stop();
}

void turn_left(int m)
{
    set_create_total_angle(0);
    while (get_create_total_angle()< m)
    {
        create_drive_direct(0,200);
    }
    create_stop();
}

void backup(int m)
{
    set_create_distance(0);
    while (get_create_distance()<( m))
    { 
        create_drive_direct(-200,-200);
    }
}

void arm_up()
{
    int a= 1988;
    while (a>594)
    {
        set_servo_position(1,a);
        msleep(200);
        a=a -70;
    }
}
void arm_down()
{
    int d= 1000;
    while(d<1850)
    {
        set_servo_position(1,d);
        msleep(100);
        d=d +50;
    }
}
void claw_up()
{
    int b= 700;
    while(b<2000)
    {
        set_servo_position(3,b);
        msleep(200);
        b=b +50;
    }
}
void claw_down()
{
    int c= 2000;
    while(c>550)
    {
        set_servo_position(3,c);
        msleep(100);
        c=c -50;
    }
}
void claw_close()
{
    int e= 1000;
    while(e<1950)
    {
        set_servo_position(2,e);
        msleep(100);
        e=e +70;
    }
}
void hit_wall()
{  

    while((digital(0) ==0)&&(digital(1)==0))
    {
        create_drive_direct(-200,-200);     
    }
}
void building_claw_down()

{  
    set_servo_position(3,1570);
}
void building_claw_up()
    
{
    set_servo_position(3,1835);
}
    
    