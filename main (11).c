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
int f = 0;




int main()
{
    create_connect();
    enable_servos();
    //claw open
    claw_open();
    msleep(500);

    //claw down
    claw_down();
    msleep(200);
    //arm down
    arm_down();
    msleep(300);
    //claw close to grab ambulence
    claw_close();
    msleep(200);
    // turn left to hospital
    turn_left(90);
    msleep(200);
    //arm up
    arm_up();
    msleep(300);
    claw_up();
    ao();
    // to hospital
    go_forward(450);
    // turn to hospital
    turn_right(-40);
    msleep(200);
    // fire detection
    int iteration_count=0;
    int update_errors=0;
    camera_open_black();

    while (digital (8) ==0)
    {
        if (!camera_update())
        {
            update_errors++;
            continue;
        }
        if (iteration_count >1000)
        {
            iteration_count= 0;
            camera_close();
            camera_open_black();
        }
        msleep (300);
        if(get_object_count (0)==0)
        {
            printf("No fire found!\n");
            create_stop();      
            claw_down();
            arm_down();
            claw_open();


        }
        else
        { 
            printf("Found fire!\n");
            turn_right(-10);
            go_forward(230); 
            claw_down();
            arm_down();
            claw_open();
            create_stop();
        }

        camera_close();

    }

    backup(-1140);
 create_stop();
    msleep(1000);  
    
    
    turn_right(-40);
    create_stop();
    hit_wall();

    disable_servos();

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
    int a= 1900;
    while (a>1025)
    {
        set_servo_position(1,a);
        msleep(200);
        a=a -70;
    }
}
void arm_down()
{
    int d= 1025;
    while(d<1900)
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
    while(c>650)
    {
        set_servo_position(3,c);
        msleep(100);
        c=c -50;
    }
}
void claw_close()
{
    int e= 1000;
    while(e<1825)
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



