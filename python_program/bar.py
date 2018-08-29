
import sys

if(sys.version_info[0] < 3):
    print("This program is written with Python 3.x")
    print("Run \'Python3 filename.py\' to propperly run the program")
    sys.exit(1)

else:
    # Do work here
    from subprocess import call

    def main():
        import time
        loading_bar = []
        dashes = 1
        spaces = 10

        for i in range(11):
            print("Loading[", end="")
            for x in range(dashes):
                print("|", end="")
            for y in range(spaces):
                print(end=" ")
            time.sleep(.25)
            dashes += 1
            spaces -= 1
            print("]")
            time.sleep(0.5)
            call(["clear"])
        pass

    if __name__ == '__main__':
        call(["clear"])
        sys.exit(main())
