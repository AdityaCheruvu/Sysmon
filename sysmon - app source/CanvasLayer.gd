extends CanvasLayer

# class member variables go here, for example:
# var a = 2
# var b = "textvar"
var screen
var sizeForEachMeter
var meters = []
var scene
func _ready():
	# Called every time the node is added to the scene.
	# Initialization here
	screen = get_viewport().size
	screen[1] = screen[1]/2
	sizeForEachMeter = screen
	sizeForEachMeter[0] = sizeForEachMeter[0]/2
	sizeForEachMeter[1] = sizeForEachMeter[1]/4
	var posForEach = sizeForEachMeter
	posForEach[0] = sizeForEachMeter[0]/4
	posForEach[1] = sizeForEachMeter[1]*1.1
	print(sizeForEachMeter)
	scene = preload("res://CPUMeter.tscn")
	for i in range(global.govern.numberOfCpus()):
		meters.append(scene.instance())
		add_child(meters[-1])
		meters[-1].orient(posForEach, i)
		if(i%2 == 0):
			posForEach[0]+=sizeForEachMeter[0]*0.6
		else:
			posForEach[0]-=sizeForEachMeter[0]*0.6
			posForEach[1]+=sizeForEachMeter[1]*2.7
		

#func _process(delta):
#	# Called every frame. Delta is time since last frame.
#	# Update game logic here.
#	pass
