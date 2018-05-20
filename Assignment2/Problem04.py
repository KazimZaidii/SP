import datetime
import os
import psutil
import sys

def main():
    pid = sys.argv[1]
    process = psutil.Process(int(pid))
    p_name = process.name()
    p_status = process.status()
    p_ppid = process.ppid()
    p_ppname = psutil.Process(process.ppid()).name()
    p_creation = process.create_time()
    p_files = process.open_files()
    p_memory = process.memory_info()
    print("process id: " + str(pid))
    print("process name: " + str(p_name))
    print("process status: " + str(p_status))
    print("process parent id: " + str(p_ppid))
    print("process parent name: " + str(p_ppname))
    print("process creation time: " + str(p_creation))
    print("files opened by process: " + str(p_files))
    print("process memory info: " + str(p_memory))

if __name__ == '__main__':
    main()