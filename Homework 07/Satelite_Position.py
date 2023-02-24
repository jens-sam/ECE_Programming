#!/usr/bin/python3

# start of program
import sys
import json
import numpy as np
import pandas
import pandas as pd
import scipy as sc
from scipy import integrate
from matplotlib import pyplot as plt
import matplotlib


def dataFrame(cal, imu, out):
    """
    Your job is to receive the raw IMU data and calculate and plot the position, orientation
    and velocity of the satellite as a function of time.

    An IMU consists of a 3 axis accelerometer and a 3 axis gyroscope

    :param cal: json cal file with dictionary data for xyz and roll pitch yaw scale
    :param imu: data table for time and 6 positions at time
    :param out: outfile created
    :return:
    """

    with open("cal.json", "r") as f:
        cal = json.load(f)

    # read file
    df = pd.read_csv("imu.csv")

    # setting up the x y z value positions to be the same of 4000 and not 3999 vs 4000
    df.insert(2, "v_x", np.zeros(4000))
    df.insert(3, "v_y", np.zeros(4000))
    df.insert(4, "v_z", np.zeros(4000))

    # meters per second and radians per second, integrating once
    df['v_x'][1:] = integrate.cumtrapz((df['a_x'] * cal['a_x_scale']), df['time'], dx=1.0, axis=-1, initial=None)
    df['v_y'][1:] = integrate.cumtrapz((df['a_y'] * cal['a_y_scale']), df['time'], dx=1.0, axis=-1, initial=None)
    df['v_z'][1:] = integrate.cumtrapz((df['a_z'] * cal['a_z_scale']), df['time'], dx=1.0, axis=-1, initial=None)

    df.insert(5, "x", np.zeros(4000))
    df.insert(6, "y", np.zeros(4000))
    df.insert(7, "z", np.zeros(4000))

    # integrate again for y values of v_x,y,z
    df['x'][1:] = integrate.cumtrapz((df['v_x']), df['time'], dx=1.0, axis=-1, initial=None)
    df['y'][1:] = integrate.cumtrapz((df['v_y']), df['time'], dx=1.0, axis=-1, initial=None)
    df['z'][1:] = integrate.cumtrapz((df['v_z']), df['time'], dx=1.0, axis=-1, initial=None)

    # plotting format
    fig, axs = plt.subplots(3)

    axs[0].set_ylabel("Position [m]")
    df.plot(x='time', y=['x', 'y', 'z'], ax=axs[0])

    axs[1].set_ylabel("Velocity [m/s]")
    df.plot(x='time', y=['v_x', 'v_y', 'v_z'], ax=axs[1])

    axs[2].set_ylabel("Acceleration [m/s^2]")
    df.plot(x='time', y=['a_x', 'a_y', 'a_z'], ax=axs[2])

    # save the figures (uncomment)
    plt.savefig('{}_linear.png'.format(imu))
    # plt.show()

    # calculate for roll now
    # setting up the roll pitch yaw value positions to be the same of 4000 and not 3999 vs 4000
    df.insert(11, "roll", np.zeros(4000))
    df.insert(12, "pitch", np.zeros(4000))
    df.insert(13, "yaw", np.zeros(4000))

    # meters per second and radians per second integrate first time for roll pitch yaw
    df['roll'][1:] = integrate.cumtrapz((df['v_roll'] * cal['v_roll_scale']), df['time'], dx=1.0, axis=-1, initial=None)
    df['pitch'][1:] = integrate.cumtrapz((df['v_pitch'] * cal['v_pitch_scale']), df['time'], dx=1.0, axis=-1, initial=None)
    df['yaw'][1:] = integrate.cumtrapz((df['v_yaw'] * cal['v_yaw_scale']), df['time'], dx=1.0, axis=-1, initial=None)

    df.insert(17, "a_roll", np.zeros(4000))
    df.insert(18, "a_pitch", np.zeros(4000))
    df.insert(19, "a_yaw", np.zeros(4000))

    # dv/dt (derivative calculation)
    # partial v_roll / partial time = diff(v_roll)/diff(time)
    # partial a_pitch / partial time = diff(a_pitch)/diff(time)
    # partial a_yaw / partial time = diff(a_yaw)/diff(time)
    df['a_roll'] = df['v_roll'].diff() / df['time'].diff()
    df['a_pitch'] = df['v_pitch'].diff() / df['time'].diff()
    df['a_yaw'] = df['v_yaw'].diff() / df['time'].diff()

    # plotting yaw
    fig, axs = plt.subplots(3)

    axs[0].set_ylabel("Position [m]")
    df.plot(x='time', y=['roll', 'pitch', 'yaw'], ax=axs[0])

    axs[1].set_ylabel("Velocity [m/s]")
    df.plot(x='time', y=['v_roll', 'v_pitch', 'v_yaw'], ax=axs[1])

    axs[2].set_ylabel("Acceleration [m/s^2]")
    df.plot(x='time', y=['a_roll', 'a_pitch', 'a_yaw'], ax=axs[2])

    # if you want to print the data frame array
    # print(df)

    # saving figures for angular (uncomment)
    plt.savefig('{}_angular.png'.format(imu))
    plt.show()

    # saving outfile to csv (uncomment)
    # df.to_csv(out, index=False, float_format='%.6e')


def main():

    l = len(sys.argv)

    if l == 4:
        # print(sys.argv[1], sys.argv[2], sys.argv[3])
        cal = sys.argv[1]
        imu = sys.argv[2]
        out = sys.argv[3]
        dataFrame(cal, imu, out)
    else:
        print("didnt do it right")
        sys.exit(1)


if __name__ == "__main__":
    main()
