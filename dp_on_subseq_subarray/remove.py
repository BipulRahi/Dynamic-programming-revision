import os
curdir = os.getcwd()
exe_files = [file for file in os.listdir(curdir) if file.endswith(".exe")]
for file in exe_files:
    os.remove(file)
    print("Deleted"+ file +" files.")
    
    