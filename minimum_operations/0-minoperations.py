#!/usr/bin/python3
"""
Main file for testing
"""


def minOperations(n):
    if n <= 1:
        return 0
    if n <= 3:
        return n

    h = 0
    m = 2
    value = n
    if n % 2 != 0:
        j = 1
    while value > 1:
        
        while value % m == 0:
            
            value = value // m
            print(value)
            h += m
        m += 1

    return h

Curriculum
[C#22] Interview Preparation - Algorithms
Average: 97.4%
Project badge
81.82%
Log Parsing
 Amateur
 By: Alexa Orrico, Software Engineer at Holberton School
 Weight: 1
 Your score will be updated as you progress.
Description
Requirements
General
Allowed editors: vi, vim, emacs
All your files will be interpreted/compiled on Ubuntu 14.04 LTS using python3 (version 3.4.3)
All your files should end with a new line
The first line of all your files should be exactly #!/usr/bin/python3
A README.md file, at the root of the folder of the project, is mandatory
Your code should use the PEP 8 style (version 1.7.x)
All your files must be executable
The length of your files will be tested using wc
Tasks
0. Log parsing
mandatory
Score: 81.82% (Checks completed: 81.82%)
Write a script that reads stdin line by line and computes metrics:

Input format: <IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size> (if the format is not this one, the line must be skipped)
After every 10 lines and/or a keyboard interruption (CTRL + C), print these statistics from the beginning:
Total file size: File size: <total size>
where <total size> is the sum of all previous <file size> (see input format above)
Number of lines by status code:
possible status code: 200, 301, 400, 401, 403, 404, 405 and 500
if a status code doesn’t appear or is not an integer, don’t print anything for this status code
format: <status code>: <number>
status codes should be printed in ascending order
Warning: In this sample, you will have random value - it’s normal to not have the same output as this one.

alexa@ubuntu:~/log_parsing$ cat 0-generator.py
#!/usr/bin/python3
import random
import sys
from time import sleep
import datetime

for i in range(10000):
    sleep(random.random())
    sys.stdout.write("{:d}.{:d}.{:d}.{:d} - [{}] \"GET /projects/260 HTTP/1.1\" {} {}\n".format(
        random.randint(1, 255), random.randint(1, 255), random.randint(1, 255), random.randint(1, 255),
        datetime.datetime.now(),
        random.choice([200, 301, 400, 401, 403, 404, 405, 500]),
        random.randint(1, 1024)
    ))
    sys.stdout.flush()

alexa@ubuntu:~/log_parsing$ ./0-generator.py | ./0-stats.py 
File size: 5213
200: 2
401: 1
403: 2
404: 1
405: 1
500: 3
File size: 11320
200: 3
301: 2
400: 1
401: 2
403: 3
404: 4
405: 2
500: 3
File size: 16305
200: 3
301: 3
400: 4
401: 2
403: 5
404: 5
405: 4
500: 4
^CFile size: 17146
200: 4
301: 3
400: 4
401: 2
403: 6
404: 6
405: 4
500: 4
Traceback (most recent call last):
  File "./0-stats.py", line 15, in <module>
Traceback (most recent call last):
  File "./0-generator.py", line 8, in <module>
    for line in sys.stdin:
KeyboardInterrupt
    sleep(random.random())
KeyboardInterrupt
alexa@ubuntu:~/log_parsing$ 
Repo:

GitHub repository: holbertonschool-interview
Directory: log_parsing
File: 0-stats.py
  
×
Correction of "0. Log parsing"
Some checks are failing. Make sure you fix them before starting a new review
You got this!
 
Result:
File is present

First line contains #!/usr/bin/python3

Module is documented

Correct output - case: One line of log

Correct output - case: 10 lines

Correct output - case: 10 lines only 200 status

Correct output - case: empty file

Correct output - case: long log

Correct output - case: wrong format

[copy_files] Filed copied: file_5
[compare] Command to run:
cat file_5 | ./0-stats.py
su student_jail -c 'timeout 30 bash -c '"'"'cat file_5 | ./0-stats.py'"'"''
[compare] Return code: 0
[compare] Student stdout:
['99.196.100.39', '-', '[2017-02-05', '23:31:22.954433]', '"GET', '/projects/260', 'HTTP/1.1"', '401', '658']
['128.230.61.246', '-', '[2017-02-05', '23:31:23.258076]', '"GET', '/projects/260', 'HTTP/1.1"', 'Hello', '292']
['116.82.223.35', '-', '[2017-02-05', '23:31:24.112360]', '"GET', '/projects/260', 'HTTP/1.1"', '301', '842']
['Holberton', '-', '[2017-02-05', '23:31:25.003550]', '"GET', '/projects/260', 'HTTP/1.1"', '400', '12']
['7.179.133.121', '-', '[2017-02-05', '23:31:25.003550]', '"GET', '/projects/260', 'HTTP/1.1"', '400', '12']
['188.213.11.218-[2017-02-05', '23:31:21.690755]', '"GET', '/projects/260', 'HTTP/1.1"', '401', '1000']
['128.230.61.246', '-', '[2017-02-05', '23:31:23.258076]', '"GET', '/projects/260', 'HTTP/1.1"', '301', '292']
File size: 711
200: 1
[compare] Student stdout length: 784
[compare] Student stderr:
[compare] Student stderr length: 0
[compare] Desired stdout:
File size: 3819
200: 1
301: 2
400: 2
401: 2
[compare] Desired stdout length: 44
PEP8 validation


20 correction requests
9/11 pts
Score
Project badge
81.82%
Your score will be updated as you progress.

Please review all the tasks before you start the peer review.

Tasks list
Mandatory
Advanced

