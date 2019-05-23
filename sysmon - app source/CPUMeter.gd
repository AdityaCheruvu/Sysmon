extends Node2D

# class member variables go here, for example:
# var a = 2
# var b = "textvar"

var needlePlacement
var pos
var del
var control

func orient(pos, cont):
	$meter.position = pos
	$needle.position = $meter.position + Vector2(-60, 141)
	$Label.rect_position = $needle.position + Vector2(0, 50)
	get_node("needle/needlepng").position = get_node("needle/needlepng").position + needlePlacement
	get_node("needle").rotation_degrees = 77.5
	control = cont
	if(control!=-1):
		scale[0] = global.meterScale
		scale[1] = global.meterScale

func _ready():
	# Called every time the node is added to the scene.
	# Initialization here
	needlePlacement = Vector2(0, -60)
	set_process(true)
	
	
	#pos = Vector2(400, 500)
	#orient(pos)
	#set_process(true)
	
func rotor(control):
	
	if(control == -1):
		var s = global.govern.cpuAvg()
		$Label.set_text(String(s*100) + "%")
		return s
	else:
		var s1= global.govern.cpu(int(control))
		$Label.set_text(String(s1*100) + "%")
		return s1

func _process(delta):
#	# Called every frame. Delta is time since last frame.
#	# Update game logic here.
		var l = rotor(control)
		get_node("needle").rotation_degrees = 165*l - 87.5
    