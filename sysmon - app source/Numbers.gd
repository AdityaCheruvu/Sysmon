extends Label

# class member variables go here, for example:
# var a = 2
# var b = "textvar"

func _ready():
	# Called every time the node is added to the scene.
	# Initialization here
	pass

func _process(delta):
	var s = String(global.govern.swapUsed())
	var tm = String(global.govern.swapTot())
	set_text(s+"  kb out of  "+tm+"  kb")
