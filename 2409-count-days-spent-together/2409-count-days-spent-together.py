class Solution(object):
    def countDaysTogether(self, arriveAlice, leaveAlice, arriveBob, leaveBob):
        """
        :type arriveAlice: str
        :type leaveAlice: str
        :type arriveBob: str
        :type leaveBob: str
        :rtype: int
        """
        months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

        arriveAlice = arriveAlice.split("-")
        arriveAlice = [int(arriveAlice[0]),int(arriveAlice[1])]
        leaveAlice = leaveAlice.split("-")
        leaveAlice = [int(leaveAlice[0]),int(leaveAlice[1])]
        arriveBob = arriveBob.split("-")
        arriveBob = [int(arriveBob[0]),int(arriveBob[1])]
        leaveBob = leaveBob.split("-")
        leaveBob = [int(leaveBob[0]),int(leaveBob[1])]
        
        start = arriveBob
        stop = leaveBob

        if(arriveAlice[0] > leaveBob[0] or (arriveAlice[0] == leaveBob[0] and arriveAlice[1] > leaveBob[1])) or (arriveBob[0] > leaveAlice[0] or (arriveBob[0] == leaveAlice[0] and arriveBob[1] > leaveAlice[1])):
            return 0

        if arriveAlice[0] > arriveBob[0] or (arriveAlice[0] == arriveBob[0] and arriveAlice[1] > arriveBob[1]):
            start = arriveAlice
        if leaveAlice[0] < leaveBob[0] or (leaveAlice[0] == leaveBob[0] and leaveAlice[1] < leaveBob[1]):
            stop = leaveAlice

        startDay = start[1]
        for i in range(start[0] - 1):
            startDay = startDay + months[i]

        stopDay = stop[1]
        for i in range(stop[0] - 1):
            stopDay = stopDay + months[i]
            
        return stopDay - startDay + 1