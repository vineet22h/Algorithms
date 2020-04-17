class Tree:
	def __init__(self,data):
		self.left = None
		self.right = None
		self.root = data	
		
class Queue:
	def __init__(self):
		self.queue = list()
	def enqueue(self,data):
		self.queue.insert(0,data)
	def dequeue(self):
		if len(self.queue) > 0:
			return self.queue.pop()
		return -1;
	def size(self):
		return len(self.queue)
	def printQueue(self):
		print(self.queue)

class BFS:

	def __init__(self,head):
		self.q = Queue()
		self.a = head
	def fetch(self):
		index = 1
		self.q.enqueue(self.a)
		while self.q.size()!=0:
		 	elem = self.q.dequeue()
		 	print(elem.root)
		 	if elem.left != None:
		 		self.q.enqueue(elem.left)
		 	if elem.right != None:
		 		self.q.enqueue(elem.right)

head = Tree(5)
head.left = Tree(4)
head.right = Tree(3)
head.left.left = Tree(9)
head.left.right = Tree(19)

f = BFS(head)
f.fetch()