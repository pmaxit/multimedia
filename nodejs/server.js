var desktopClientSocket;

var socketServer = new (require('ws').Server)({port: 8080}); // general clients
var desktopSocketServer = new (require('ws').Server)({port: 8081}) // this is for desktop clients

socketServer.on('connection', function(socket){
  console.log('New web socket connection ('+ socketServer.clients.length + 'total)');

  socket.on('close', function(code, message){
    console.log('Disconnected web socket ('+socketServer.clients.length +'total)');
  }); 
  
  // message received from client
  socket.on('message', function(message){
      // send it to desktop client
    console.log("> "+ message);
    if(desktopClientSocket != null){
      desktopClientSocket.send(message);
      console.log("message sent %s", message);
    }
    else
      console.log("desktop client socket not connected");
  });
});

desktopSocketServer.on('connection', function(socket){
  if(desktopClientSocket == null)
    desktopClientSocket = socket;
  
  var streamHeader = new Buffer(1)
  streamHeader.write('w');
  socket.send(streamHeader, {binary:true})

  socket.on('close', function(code, message){
    console.log('Disconnected WebSocket ('+ desktopServer.clients.length + ' total )');
    desktopClientSocket = null;
  });

});
