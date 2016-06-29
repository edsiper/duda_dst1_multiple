# Duda I/O: Multiple Web Services

The following code is an example to load multiple web services under the same Monkey/Duda process. Since _DudaC_ is not aware about this feature, some manual setup is required:

## Steps

### Compile web service __aa__ and __bb__:

```
   $ cd aa/
   $ /path_to_dudac/dudac -w .
   $ cd ../bb/
   $ /path_to_dudac/dudac -w .
```

At this point DudaC will generate files _aa.duda_ and _bb.duda_ inside the root directory of this project. You should see some warning/error message, but you will see the _.duda_ files there.

### Configure ServicesRoot

Edit the Duda configuration file _~/.dudac/stage/monkey/conf/plugins/duda/duda.conf_ and make sure __ServicesRoot__ points to this project directory, e.g:

```
[DUDA]
    ServicesRoot /path_to/duda_dst1_multiple/
    ...other options are fine...
```

### Configure Virtual Host file

Edit the file _~/.dudac/stage/monkey/conf/sites/default_ and make sure the following content exists at bottom:

```
[WEB_SERVICE]
    Name aa
    Enabled on

[WEB_SERVICE]
    Name bb
    Enabled on
    ```

### Run the Web Services

From the command line issue a direct call to the Monkey launcher:

```
$ ~/.dudac/stage/monkey/bin/monkey
Monkey HTTP Daemon 1.4.0
Built : Apr 14 2016 20:26:57 (gcc 5.2.1)
Home  : http://monkey-project.com
[2016/06/29 08:49:43] [   Info] Linux TCP_FASTOPEN
* Process ID is 6143
* Server socket listening on Port 2001
* 4 threads, 126 client connections per thread, total 504
* Transport layer by liana in http mode
[2016/06/29 08:49:43] [   Info] Duda: loading service 'aa'
[2016/06/29 08:49:43] [   Info] Duda: loading service 'bb'
[2016/06/29 08:49:43] [   Info] HTTP Server started
```

Now you can test both web services as follows:

```
$ curl -i http://127.0.0.1:2001/aa/test
HTTP/1.1 200 OK
Server: Monkey/1.4.0
Date: Wed, 29 Jun 2016 14:50:13 GMT
Content-Length: 11

This is AA
```

```
$ curl -i http://127.0.0.1:2001/bb/test
HTTP/1.1 200 OK
Server: Monkey/1.4.0
Date: Wed, 29 Jun 2016 14:50:16 GMT
Content-Length: 11

This is BB
```
