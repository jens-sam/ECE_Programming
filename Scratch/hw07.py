import sys

import numpy as np
import pandas
import pandas as pd
from matplotlib import pyplot as plt
from scipy import integrate
import json


def main(calibration_file, imu_file, out_file):
    new_list = [1, 2, 3]

    """
    calibration file, imu data file, and output file which is csv
    continaing
    
    so we a_x_scale, a_y_scale, a_z_scale, v_roll_scale, v_pitch_scale, v_yaw_scale from json
    file in a dictionary
    
    then from imu_file we will receive data
    time_stamp, x_accel_ADC, y_accel_ADC, z_accel_ADC, x_gyro_ADC, y_gyro_ADC, z_gyro_ADC
    
    we need to output a CSV in the format:
    
    <timestamp>,<x>,<y>,<z>,<roll>,<pitch>,<yaw><v_x>,<v_y>,<v_z>,
    <v_roll>,<v_pitch>,<v_yaw>,<a_x>,<a_y>,<a_z>,<a_roll>,<a_pitch>,
    <a_yaw>\n
    
    """
    with open(calibration_file, "r") as f:
        cal = json.load(f)

    # assign variables to the values in the dictionary
    ax = cal["a_x_scale"]
    ay = cal["a_y_scale"]
    az = cal["a_z_scale"]
    vr = cal["v_roll_scale"]
    vp = cal["v_pitch_scale"]
    vy = cal["v_yaw_scale"]

    ax_cal = integrate.cumtrapz(ax[1])
    ay_cal = integrate.cumtrapz(ay[2])
    az_ = integrate.cumtrapz(az[3])
    
    d = pd.read_csv(imu_file).to_numpy().transpose()
    print(d)

    # acceleration = column a_y in csv, x = time
    vx = integrate.cumtrapz(d[3], x=d[1])
    print(vx)

    """Existing work
    df.plot()
    plt.show()
    df.plot(x="f")
    plt.show()
    # df is data frame
    d = df.to_numpy()
    plt.semilogx(d[0, d[2]])
    plt.show()
    # numpy.matrix.transpose
    # make data frame with to _numpy and transpose together
    d = df.to_numpy().transpose
    plt.semilogx(d[0, d[2]])
    plt.show()
    # turn it into decibals to read
    dB = 20 * np.log10(d[2] / d[1])
    plt.semilogx(d[0], dB)
    plt.show()
    # phase calculating
    phs = 360 * d[0] * d[3]
    plt.semilogx(d[0], phs)
    plt.show()
    # making graphs with subfigure plots
    # fig, ax = plt.subplots()
    # ax.plot(x, y)
    # ax.set_title('a single plot')
    f, ax = plt.subplots(2)
    f.set_title("Bode Plot")
    ax[1].set(ylabel="Phase [deg]")
    ax[0].semilogx(d[0], dB)
    ax[1].semilogx(d[0], phs)
    ax[1].set(ylabel="Phase [deg]")
    plt.show()
    # specify size and save the figures
    plot.savefig("example.png")
    # pulling slices out
    d[0]
    d[0:1]
    d[0:]
    d[1:2]  # we do columns one to three
    # shapes
    d.shape()
    shape(d)  # call
    d.size
    # from scipy import integrate
    a = integrate.cumtrapz(d[0])
    # import pandas as pd
    d = pd.read_csv("imu.csv").to_numpy().transpose()
    df = pd.read_csv("imu.csv")
    # call df
    # from scipy import integrate
    # acceleration = column a_y in csv, x = time 
    vx = integrate.cumtrapz(d[3], x=d[1])
    # import matplotlib.pyplot as plt
    plt.plot(d[1], d[3])
    plt.plot(d[1], vx)  # throws error
    # can do it this way
    plt.plot(d[1][1:], vx)
    # another way
    vx = np.zeros(len(d[1]))
    vx[1:] = integrate.cumtrapz(d[3], x=d[1])
    plt.plot(d[1], d[3])
    plt.plot(d[1], vx)
    plt.show()
    """


if __name__ == "__main__":
    if len(sys.argv) == 4:
        main(sys.argv[1], sys.argv[2], sys.argv[3])
    else:
        print("Usage: python3 hw07.py <calibration_file> <imu_file> <out_file>")
        sys.exit(1)
