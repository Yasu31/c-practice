var app=require('express')();
// express is a web framework.
var http=require('http').Server(app);
var io=require('socket.io')(http);

// define route handler
app.get('/', function(req, res){
    res.sendFile(__dirname+'/index.html');;
});

io.on('connection', function(socket){
    console.log('a user connected');
    socket.on('disconnect', function(){
	console.log('user disconnected');
    });
    socket.on('chat message', function(msg){
	console.log('message: ' +msg);
	io.emit('chat message', msg);
    });
});

// make http server listen on port 3000
http.listen(3000, function(){
    console.log('listening on *:3000');
});
