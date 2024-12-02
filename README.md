# Autonomous Obstacle-Clearing Robot

[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=16406266&assignment_repo_type=AssignmentRepo)

---

## **Project Purpose**

This project focuses on designing and developing a robot capable of autonomously clearing a 3 m x 3 m space populated with wooden cubes.  
The robot utilizes **IR sensors** and **line follower sensors** to navigate and interact with its environment by clearing blocks from the space without hitting obstacles.

---

## **Setup Instructions**

1. Upload the code from the `main` file to the Arduino UNO.
2. Connect motors and sensors according to the provided schematics.

---

## **Usage**

- Power on the Arduino UNO after all connections are in place.  
- Ensure the motors and sensors are functioning as expected before deploying the robot in the designated area.  
- The robot will begin clearing blocks while avoiding obstacles.

---

## **Technologies Used**

- **Control Mechanism**: Superloop architecture is implemented to process sensor data and make decisions sequentially.  
- **Sensors and Components**:
  - 2 IR Sensors
  - 2 Line Follower Sensors
  - Motor Controller
  - 1 Analog IR Sensor  

The superloop handles input from each sensor one at a time, identifying black lines or obstacles as they are detected.

---

## **Contributors**

- **Ali Nadim**  
- **Taran Basati**  
- **Mohamed Elhosary**  
- **Arkash Sunderilgham**  

---

