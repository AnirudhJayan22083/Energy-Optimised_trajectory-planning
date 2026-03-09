# Energy-Optimised_trajectory-planning

This project focuses on improving the **energy efficiency and motion smoothness of a 4-DOF robotic manipulator** by optimizing its trajectory. The system compares a **normal inverse kinematics trajectory** with an **optimized trajectory** and evaluates their performance using **FFT-based vibration analysis**.

The goal is to generate robot motions that **reduce vibration and improve overall motion efficiency**.

---

# Authors

**Group A-2**

- Anirudh Jayan – CB.SC.U4AIE24007  
- Sarvesh Ram Kumar – CB.SC.U4AIE24048  
- Aravind S Harilal – CB.SC.U4AIE24008  
- Adhwaidh – CB.SC.U4AIE24003  

---

# Project Overview

Robotic manipulators typically follow trajectories generated using inverse kinematics. While these trajectories reach the desired positions, they can introduce **unnecessary vibration and inefficient motion**.

This project improves the trajectory by:

1. Generating a base trajectory using **inverse kinematics**  
2. Modifying the trajectory using **Fourier-based shaping**  
3. Optimizing the trajectory parameters using **Nelder–Mead optimization**  
4. Measuring vibration using an **accelerometer**  
5. Evaluating vibration energy using **Fast Fourier Transform (FFT)**  

The optimized trajectory aims to produce **smoother motion and reduced vibration energy**.

---

# Methodology

The system follows these main steps.

## 1. Trajectory Generation

A trajectory for the robotic manipulator is generated using **inverse kinematics**.  
This produces the baseline motion used for comparison.

---

## 2. Fourier-Based Trajectory Shaping

To improve the trajectory, small **sinusoidal components (Fourier terms)** are added to the base joint motion.

These Fourier coefficients act as **adjustable parameters** that change the shape of the trajectory.  
By tuning these parameters, the motion can be made smoother and less aggressive.

---

## 3. Optimization using Nelder–Mead

The Fourier coefficients are optimized using the **Nelder–Mead algorithm**.

The optimizer searches for coefficient values that produce trajectories with:

- smoother velocity profiles  
- lower acceleration  
- reduced vibration

---

## 4. FFT-Based Vibration Evaluation

During robot motion, an **accelerometer** records vibration along three axes.

The vibration signals are processed using **Fast Fourier Transform (FFT)** to analyze their frequency components.

Only the **4–7 Hz frequency band**, which corresponds to the dominant structural vibration of the manipulator, is considered.

The vibration energy in this frequency band is used as a **performance metric**.

---

# How FFT Is Used in the Optimization

FFT plays an important role in evaluating how good a trajectory is.

1. The robot executes a trajectory and vibration data is collected.  
2. FFT is applied to the acceleration signals to compute vibration energy.  
3. This vibration energy is used to estimate how much vibration the trajectory produces.  
4. The optimization function uses this information to guide the search toward trajectories that produce **lower vibration energy**.

In this way, the optimization algorithm gradually finds **trajectory parameters that reduce vibration and improve motion efficiency**.

---

# Experimental Evaluation

Two types of trajectories are tested:

- **Normal inverse kinematics trajectory**
- **Optimized trajectory using Fourier shaping and Nelder–Mead**

For each case:

- Accelerometer data is recorded  
- FFT analysis is performed  
- Vibration energy is computed and compared

---

# Technologies Used

- Python  
- NumPy  
- SciPy  
- PySerial  
- Fast Fourier Transform (FFT)  
- Nelder–Mead Optimization  

---

# Outcome

The optimized trajectory demonstrates:

- reduced vibration energy  
- smoother joint motion  
- improved efficiency compared to the standard trajectory.
