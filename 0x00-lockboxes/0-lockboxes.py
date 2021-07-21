#!/usr/bin/python3
""" Method """


def canUnlockAll(boxes):
    ''' Method that determines if all boxes can be opened '''
    checkList = [0]
    length = len(boxes)

    if boxes is None or length == 0:
        return False
    for x in checkList:
        for outterList in boxes[x]:
            if outterList >= length:
                continue
            if outterList not in checkList:
                checkList.append(outterList)

    if len(checkList) == length:
        return True
    return False
