class edge:
	def __init__(self,source,destination,weight):
		self.src = source
		self.destination = destination
		self.wt = weight

class kruskal:
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
		self.edges = list()
		self.output = list()

	def undirected_all_edges(self):
		for i in range(self.vertices):
			for j in range(i,self.vertices):
				wt = self.graph[i][j]
				if wt>0:
					self.edges.append(edge(i,j,self.graph[i][j]))

	def printEdges(self):
		for i in range(self.vertices):
			print(self.edges[i].src ,self.edges[i].destination ,self.edges[i].wt)

	def swap(self,i,j):
		self.edges[i],self.edges[j] = self.edges[j],self.edges[i]
		
	def sort(self):
		for i in range(self.vertices):
			for j in range(1,self.vertices):
				if self.edges[j-1].wt > self.edges[j].wt:
					self.swap(j-1,j)

	def undirected_isCycle(self,node,to):
		while(True):
			flag = 0
			for i in range(len(self.output)):
				if self.output[i].destination == to :
					to = self.output[i].src
					flag = 1
					if to == node:
						return True

				if self.output[i].destination == node:
					node = self.output[i].src
					flag = 1
					if node == to:
						return True
						
			if flag == 0:
				return False
	
	def algo(self):
		self.all_edges()
		self.printEdges()
		self.sort()
		print(" ")
		self.printEdges()
		# print(self.isCycle(2,3))
		for i in range(self.vertices):
			if not self.isCycle(self.edges[i].src,self.edges[i].destination):
				self.output.append(edge(self.edges[i].src,self.edges[i].destination,self.edges[i].wt))

		print(" ")

		for i in range(len(self.output)):
			print(self.output[i].src,self.output[i].destination,self.output[i].wt)

t = kruskal()
t.algo()