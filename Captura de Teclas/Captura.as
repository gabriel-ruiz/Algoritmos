// Action Script 2.0

onEnterFrame = function ()
{
 if (Key.isDown (Key.CONTROL) && Key.isDown (67))
 {
  trace ("Ctrl+C pressed");
  status_txt.text = "Ctrl+C pressed";
 }
 if (Key.isDown (Key.CONTROL) && Key.isDown (86))
 {
  trace ("Ctrl+V pressed");
  status_txt.text = "Ctrl+V pressed";
 }
 if (Key.isDown (Key.CONTROL) && Key.isDown (77))
 {
  trace ("Ctrl+M pressed");
  status_txt.text = "Ctrl+M pressed";
 }
};

// Action Script 3.0

stage.addEventListener (Event.ENTER_FRAME, tr);
 
function tr (event:Event):void
{
trace("t")
stage.addEventListener (KeyboardEvent.KEY_DOWN,keyDownHandler);
}
 
function keyDownHandler (event:KeyboardEvent):void
{
if (event.ctrlKey && (event.keyCode==86))
{
trace ("ctrl+v");
status_txt.text = "ctrl+v";
}
if (event.ctrlKey && (event.keyCode==88))
{
trace ("ctrl+x");
status_txt.text = "ctrl+x";
}
}