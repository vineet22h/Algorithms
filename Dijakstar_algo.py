class arr:
	def __init__(self,data,priority):
		self.data = data
		self.priority = priority
		self.index = -1

class priorityQueue:
	def __init__(self):
		self.Q = list()
		self.heapSize = -1

	def heapify(self,i):
		small = i
		left = 2*i+1
		right = 2*i+2
		
		if self.heapSize >= left and self.Q[left].priority < self.Q[small].priority:
			small = left
			
		if self.heapSize >= right and self.Q[right].priority < self.Q[small].priority:
			small = right
	
		if small != i:
			self.swap(small,i)
			self.heapify(small)

	def swap(self,i,j):
		self.Q[i].data ,self.Q[j].data = self.Q[j].data ,self.Q[i].data
		self.Q[i].priority ,self.Q[j].priority = self.Q[j].priority ,self.Q[i].priority
		self.Q[i].index ,self.Q[j].index = self.Q[j].index ,self.Q[i].index

	def parent(self,i):
		return (i-1)//2

	def enQueue(self,data,priority):
		self.heapSize += 1
		index = self.heapSize

		
		self.Q.append(arr(data,priority))
		self.Q[index].index = index
		p = self.parent(index)
		while  p >= 0:
			if  self.Q[p].priority > self.Q[index].priority:
				self.swap(p,index)
				self.Q[index].index = index 
			index = p

			p = self.parent(index)


	def printHeap(self):
		for i in range(self.heapSize+1):
			# print(self.Q[i].data,end = " ")
			print(str(self.Q[i].data)+"=>"+str(self.Q[i].priority),end = " ")
		print(" ")

	def deQueue(self):
		if self.isEmpty():
			return -1
		temp = self.Q[0]
		self.swap(self.heapSize,0)
		self.heapSize -= 1
		self.heapify(0)
		
		return temp

	def isEmpty(self):
		if self.heapSize == -1:
			return True
		return False

	def updatePriority(self,data,priority):
		for i in self.Q:
			if i.data == data:
				i.priority = priority


class Dijakstar:
	def __init__(self):
		self.vertices = 9
		self.graph = [[0, 4, 0, 0, 0, 0, 0, 8, 0], 
			          [4, 0, 8, 0, 0, 0, 0, 11, 0], 
			          [0, 8, 0, 7, 0, 4, 0, 0, 2], 
			          [0, 0, 7, 0, 9, 14, 0, 0, 0], 
			          [0, 0, 0, 9, 0, 10, 0, 0, 0], 
			          [0, 0, 4, 14,10, 0, 2, 0, 0], 
			          [0, 0, 0, 0, 0, 2, 0, 1, 6], 
			          [8, 11, 0, 0, 0, 0, 1, 0, 7], 
			          [0, 0, 2, 0, 0, 0, 6, 7, 0] 
			         ]; 
		self.pq = priorityQueue()

	def edges(self,node):
		
		for i in range(node,self.vertices):
			elem = self.graph[i][node]
			if elem >0 :
				self.pq.enQueue(i,elem)
		# self.pq.printHeap()

	def algo(self):
		distance = [-1]*self.vertices
		distance[0] = 0
		self.pq.enQueue(0,0)

		while not self.pq.isEmpty():
			temp = self.pq.deQueue()
			print(temp.data)
			self.edges(temp.data)

			w = temp.data
			temp = self.pq.deQueue()
			new_distance = self.graph[temp.index][w] + distance[w] 
			
			if distance[w] == -1:
				distance[w] = new_distance + 1
				self.pq.updatePriority(w,new_distance+1)

			if distance[w] > new_distance:
				distance[w] = new_distance
				self.pq.updatePriority(w,new_distance)
		print(distance)


t = Dijakstar()

t.algo()
