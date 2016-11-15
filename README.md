#ARCAM-NET: Selina.MeshLogic
##Software Embedded Logic In Network Application

This software will act as the control unit for ARCAM-NET applications.

Currently in early development stages.

#TODO

##Abstract Library Classes: Followed by Possible Iplementations
###Hardware Modules
	wlan0,tun0,SDR,ethernet etc.
###Mesh Modules (Proto-mesh)
	Protomesh capability will contain mesh protocol control
	Possible implementations are B.A.T.M.A.N(bat0:implements virtual hardware), 802.11s, OSLR, etc.
###Com Modules
	Any Communication modules used to communicate betweeen ARCAM nodes
	Possible implementations, 0MQ, RabbitMQ, ALFRED, etc.
###Evaluation Modules
	Utilizes other tools to evaluate the network and return an network health/condition.
	Used for making decisions
	Possible tools include, batctl ...
###Decision Making Modules
	These hold the methods of logic and decision making. decides which state/action the network needs to increase its health.
	Possible methods include decision tree, QT State Machine, Liquid State Machine, Neural Networks, etc.
###Data Modules
	Long term data collection. Might not be relevent to this software.
	batmand, MongoDB, SQL ...
