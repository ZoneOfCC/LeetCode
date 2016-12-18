# search.py
# ---------
# Licensing Information:  You are free to use or extend these projects for
# educational purposes provided that (1) you do not distribute or publish
# solutions, (2) you retain this notice, and (3) you provide clear
# attribution to UC Berkeley, including a link to http://ai.berkeley.edu.
# 
# Attribution Information: The Pacman AI projects were developed at UC Berkeley.
# The core projects and autograders were primarily created by John DeNero
# (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# Student side autograding was added by Brad Miller, Nick Hay, and
# Pieter Abbeel (pabbeel@cs.berkeley.edu).


"""
In search.py, you will implement generic search algorithms which are called by
Pacman agents (in searchAgents.py).
"""

import util
import time
from random import choice
class SearchProblem:
    """
    This class outlines the structure of a search problem, but doesn't implement
    any of the methods (in object-oriented terminology: an abstract class).

    You do not need to change anything in this class, ever.
    """

    def getStartState(self):
        """
        Returns the start state for the search problem.
        """
        util.raiseNotDefined()

    def isGoalState(self, state):
        """
          state: Search state

        Returns True if and only if the state is a valid goal state.
        """
        util.raiseNotDefined()

    def getSuccessors(self, state):
        """
          state: Search state

        For a given state, this should return a list of triples, (successor,
        action, stepCost), where 'successor' is a successor to the current
        state, 'action' is the action required to get there, and 'stepCost' is
        the incremental cost of expanding to that successor.
        """
        util.raiseNotDefined()

    def getCostOfActions(self, actions):
        """
         actions: A list of actions to take

        This method returns the total cost of a particular sequence of actions.
        The sequence must be composed of legal moves.
        """
        util.raiseNotDefined()


def tinyMazeSearch(problem):
    """
    Returns a sequence of moves that solves tinyMaze.  For any other maze, the
    sequence of moves will be incorrect, so only use this for tinyMaze.
    """
    from game import Directions
    s = Directions.SOUTH
    w = Directions.WEST
    return  [s, s, w, s, w, w, s, w]

def depthFirstSearch(problem):
    """
    Search the deepest nodes in the search tree first.

    Author: dongchangzhang @2016
    """
    # for prepare
    Open = util.Stack()
    Closed = []
    
    # start Search 
    result = generalSearch(Open, Closed, problem)
    print(result)
    return result

def breadthFirstSearch(problem):
    """
    Search the shallowest nodes in the search tree first.
    
    Author: dongchangzhang @2016
    """
    # for prepare
    Open = util.Queue()
    Closed = []

    # start Search 
    result = generalSearch(Open, Closed, problem)
    print(result)
    return result

def uniformCostSearch(problem):
    """Search the node of least total cost first."""

    # for prepare
    Open = util.PriorityQueue()
    Closed = []

    # start Search 
    result = generalSearch(Open, Closed, problem, 'P')
    print(result)
    return result

def nullHeuristic(state, problem=None):
    """
    A heuristic function estimates the cost from the current state to the nearest
    goal in the provided SearchProblem.  This heuristic is trivial.
    """
    return 0

def aStarSearch(problem, heuristic=nullHeuristic):
    """Search the node that has the lowest combined cost and heuristic first."""
    "*** YOUR CODE HERE ***"

    print("hello world!")
    util.raiseNotDefined()


def generalSearch(Open, Closed, problem, status='N'):
    """
    A function which can be used by every search method 
    input:
        arg1: Open
                type: Stack | Queue ... which has method include push and pop
        arg2: Closed
                type: list
        arg3: problem
                type:  PositionSearchProblem
        arg4: status
                type: string
                'N' : type(Open) is Stack or Queue
                'P' : type(Open) is PriorityQueue
    return:
        type: list [action1, action2,...]

    Author: dongchangzhang @2016
    """
    graph = {}
    cost = {}
    parent = None

    start_state = problem.getStartState()
    if status == 'N':
        Open.push(start_state)
    elif status == 'P':
        Open.push(start_state, 0)
    graph[start_state] = parent
    cost[start_state] = 0

    while not Open.isEmpty():
        # take out node from Open and then put it into Closed
        node_now = Open.pop()
        print(cost[node_now])
        Closed.append(node_now)
        parent = node_now
        # is goal?
        if problem.isGoalState(node_now):
            # find out way && return way
            print("IS GOAL", node_now)
            return findWay(graph, node_now)
        # else expand nodes
        successors = problem.getSuccessors(node_now)
        for node, _, weight in successors:
            if node not in graph:
                if status == 'N':
                    Open.push(node)
                elif status == 'P':
                    cost[node] = weight + cost[parent]
                    Open.push(node, cost[node])
                graph[node] = parent
    # no way, return []
    return []

def findWay(graph, goal):
    """
    input:
        arg1: graph
                type: dict {node: parent}
        arg2: goal
                type: tuple (x, y)
    return:
        type: list [action1, action2,...]
        pacman will come to location by this action list
    Author: dongchangzhang @2016
    """
    way = []
    while graph.get(goal) != None:
        way.insert(0, getAction(graph.get(goal), goal))
        goal = graph.get(goal)

    return way

def getAction(start, end):
    """
    input:
        arg1: start
                type: (x, y)
        arg2: end
                type: (x, y)
    return: action 
            'East' | 'West' | 'North' | 'South'| None (in this case: input error)
            by which pacman can go from start to end

    Author: dongchangzhang @2016
    """
    s1, e1 = start
    s2, e2 = end

    if s1 + 1 == s2 and e1 == e2:
        return 'East'
    elif s1 == s2 + 1 and e1 == e2:
        return 'West'
    elif s1 == s2 and e1 + 1 == e2:
        return 'North'
    elif s1 == s2 and e1 == e2 + 1:
        return 'South'
    else:
        print('Error At:', start, end)
        return 'None'

# Abbreviations
bfs = breadthFirstSearch
dfs = depthFirstSearch
astar = aStarSearch
ucs = uniformCostSearch



