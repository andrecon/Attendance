
import sys

if(sys.version_info[0] < 3):
    print("This program is written with Python 3.x")
    print("Run \'Python3 filename.py\' to propperly run the program")
    sys.exit(1)

else:
    # Do work here
    from subprocess import call

    def main():
        import itertools
        import threading
        import time
        import sys

        done = False
        #here is the animation
        def animate():
            #for c in itertools.cycle(['|', '/', '-', '\\']):
            for c in itertools.cycle(['|', '/', '-', '\\']):
                if done:
                    break
                sys.stdout.write('\rExiting ' + c)
                sys.stdout.flush()
                time.sleep(0.1)
            call(["clear"])

        t = threading.Thread(target=animate)
        t.start()

        #long process here
        time.sleep(10)
        done = True

        import time,sys
        pass

    if __name__ == '__main__':
        call(["clear"])
        sys.exit(main())
