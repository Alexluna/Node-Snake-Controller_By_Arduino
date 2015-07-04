var btSerial = new (require('bluetooth-serial-port')).BluetoothSerialPort();

var app = require('express')()
  , server = require('http').createServer(app)
    , io = require('socket.io').listen(server);

    server.listen(8000);

    app.get('/', function (req, res) {
	      res.sendfile(__dirname + '/public/index.html');
    });

    io.sockets.on('connection', function (socket) {


// BLUETOR
// ----------------------------------------------
// ----------------------------------------------


btSerial.on('found', function(address, name) {
		btSerial.findSerialPortChannel(address, function(channel) {
			btSerial.connect(address, channel, function() {
				console.log('connected');

				btSerial.write(new Buffer('my data', 'utf-8'), function(err, bytesWritten) {
					if (err) console.log(err);
					});



				btSerial.on('data', function(buffer) {
					
					console.log(buffer)
					var receive = buffer.toString('utf-8');
					console.log(parseInt(receive) , "<=========" );
					     socket.emit('feed', { news: receive });

					});
				}, function () {
				console.log('cannot connect');
				});

			// close the connection when you're ready
			btSerial.close();       
			});
		});

btSerial.inquire();

/*
		socket.on('temperature', function (data) {
			    console.log(data); 
			    });

*/


    });


