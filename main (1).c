#include <kipr/botball.h>
void go_forward(int m);
void turn_right(int m);
void turn_left(int m);
void backup(int m);
void find_fire();

int main()
{
    create_connect();
    turn_left(98);
    go_forward(300);
    turn_right(-45);
    msleep(200);
    find_fire();
    
    ao();
    create_disconnect();

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

void turn_right(int m)
{
    set_create_total_angle(0);
    while (get_create_total_angle()>( m))
    {
        create_drive_direct(200,0);
    }
}
void turn_left(int m)
{
    set_create_total_angle(0);
    while (get_create_total_angle()<( m))
    {
        create_drive_direct(0,200);
    }
    void backup(int m)
    {
        set_create_distance(0);
        while (get_create_distance()<( m))
        { 
            create_drive_direct(-200,-200);
        }
    }
   
void find_fire()
    {
        int iteration_count = 0;
        int update_errors = 0;
        camera_open_black();
        while (digital(8) == 0)
        {
            if(!camera_update())
            {
                update_errors++;
                continue;
            }
            if (iteration_count > 1000)
            {
                iteration_count = 0;
                camera_close();
                camera_open_black();
            } 

            if(get_object_count(0)==0) //if not seen
            {
                printf("No fire detected.\n");
                create_stop();
            }
            else
            {
                if(get_object_center_x(0,0)<80)//if on the left
                {
                    printf("fire is on the left.\n");
                    create_spin_CW(100);
                    msleep(200);
                    create_stop();
                }

                else
                {
                    create_stop();
                }
                camera_close();
            }
        }
    }}






