# Real world data problem:
** You were just hired by a large tech company which involves satellite navigation using Inertial Measurement Units (IMU). 

An IMU consists of a 3 axis accelerometer and a 3 axis gyroscope. For example 3dm-gx5-10_datasheet_8400-0095_rev_l.pdf   But of course, that is a commercial IMU that you can buy off the shelf, your company makes much more precise devices to meet the needs of precision applications.

Your job is to receive the raw IMU data and calculate and plot the position, orientation and velocity of the satellite as a function of time. 

### The "Pose" consists of 6 dimension positions: 

3 linear:  x, y, z in meters
3 angular:  roll, pitch, yaw in radians
The "Twist" consists of 6 dimension velocities: 

3 linear:  v_x, v_y, v_z in m/s
3 angular:  v_roll, v_pitch, v_yaw radians/sec
The axis are defined as:

x forward
y left
z up
roll = rotation about x axis
pitch = rotation about y axis
yaw = rotation about z axis
The IMU produces analog voltages corresponding to the linear acceleration in x,y,z and the angular velocities in roll, pitch and yaw.

The data is converted to a digital ADC value which must be scaled to real value floats using a calibration table.  The calibration table is given as a json file.

The data from the IMU comes in samples with an associated timestamp and the 6 measured values.

### Inputs:
- IMU calibration data
- Filename "cal.json"
- all values are floats
- data is a JSON file dictionary
- "a_x_scale" "a_y_scale" "a_z_scale" "v_roll_scale" "v_pitch_scale" "v_yaw_scale"
- for accelerations:  a_x=ADC_value*a_x_scale [m/s^2]
- for gyros:  v_roll=ADC_value*a_roll*scale [rad/sec]
- IMU data in comma separated format: Filename "imu.csv"
<timestamp in microseconds>,<x accel ADC>,<y accel ADC>, <z accel ADC>,<x gyro ADC>,<y gyro ADC>,<z gyro ADC>\n
- ADC values are signed integer ADC values
- First row will be column labels

### Output:

- A csv file containing
<timestamp>,<x>,<y>,<z>,<roll>,<pitch>,<yaw><v_x>,<v_y>,<v_z>,<v_roll>,<v_pitch>,<v_yaw>,<a_x>,<a_y>,<a_z>,<a_roll>,<a_pitch>,<a_yaw>\n

- all floats in scientific notation with 6 decimal accuracy
- first row should be column labels
- A plot of the linear pose and twist values with 3 subplots
- Plot of the linear Pose x,y,z
- Plot of linear Twist velocities v_x,v_y,v_z
- Plot of linear accelerations a_x,a_y,a_z
- A plot of the angular pose and twist values with 3 subplots
- Plot of the angular Pose roll, pitch, yaw
- Plot of angular velocities v_roll, v_pitch, v_yaw
- Plot of angular accelerations a_roll, a_pitch, a_yaw

Submission Requirements:
Your program must accept 3 command line arguments and be called as:

./hw07.py <calibration filename> <imu data filename> <output filename>
It must:

Save the data to <output filename>
Display the plots to the screen
AND save the graphs as '<imu filename>_linear.png', '<imu filename>_angular.png'
