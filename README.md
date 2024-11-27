# MP2-LBYARCH-AY2425
Machine Project 2 for the completion of LBYARCH, AY24-25 submitted by De Guzman, A. and De Veyra, R.

i.)  Comparative execution time and short analysis of the performance of the kernels
With both arrays entirely filled with the value 2.0:

Vector size n = 2^20
C average = 0.000005 ms
Assembly average = 0.000004 ms

Vector size n = 2^24
C average = 0.000759 ms
Assembly average = 0.000567

Vector size n = 2^29
C average = 0.012171 ms
Assembly average = 0.004893

Vector size n = 2^30
C average = 0.005936 ms
Assembly average = 0.003719 ms

Overall, despite having the exact same values and similar algorithms, the assembly kernel consistently performed about 1.25, 1.34, 1.4, and 1.21 times better than the C kernel respectively in all trials when comparing the average of 20 runs for each kernel. 

ii.) Take a screenshot of the program output with the correctness check (C).
![Screenshot 2024-11-27 223519](https://github.com/user-attachments/assets/3d854674-7424-4220-ac12-5d79c0155b50)
![Screenshot 2024-11-27 223800](https://github.com/user-attachments/assets/7e16719f-4373-47c8-82fd-1063cbac2f48)
![Screenshot 2024-11-27 224056](https://github.com/user-attachments/assets/fe4bb559-d6f2-43b8-bbf2-24a8e0b1259b)
