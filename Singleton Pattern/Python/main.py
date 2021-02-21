from threading import Lock, Thread
from time import sleep

class SingletonMeta(type):
    __instances: dict = {}
    __lock: Lock = Lock()

    def __call__(cls, *args, **kwargs):
        with cls.__lock:
            if cls not in cls.__instances:
                sleep(2)
                instance = super().__call__(*args, **kwargs)
                cls.__instances[cls] = instance
            return cls.__instances[cls]

class Singleton(metaclass=SingletonMeta):
    __value: str = None

    def __init__(self, value: str):
        self.__value = value

    def getValue(self) -> str:
        return self.__value

def test_singleton(value: str) -> None:
    obj = Singleton(value)
    print(f"Value : {obj.getValue()}")

if __name__ == "__main__":
    thread1 = Thread(target=test_singleton, args=("Foo", ))
    thread2 = Thread(target=test_singleton, args=("Bar", ))

    thread1.start()
    thread2.start()