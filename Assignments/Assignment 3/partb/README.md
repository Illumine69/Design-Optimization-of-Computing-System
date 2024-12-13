# DOCS DB Project

We were unable to complete the DPDK portion due to having issues with the DPDK setup. We have included some of our code for the DPDK portion in the `dpdk` directory.
Aside from that, we have completed the rest of the project.

### 1. **Build the Server and Client**

To build the project (server and client):

```bash
make build
```

This will compile the server and client executables

### 2. **Set up Namespaces**

To set up the required namespaces and virtual interfaces, run the following command:

```bash
./start_namespace_bridge.sh
```

This will invoke a script (`start_namespace_bridge.sh`) to create the necessary network namespaces and bridges.

Performance Metrics: (for 10,000 pks)
Total Time: 1164636 ms
Avg Latency: 116.41 ms
Total Data Sent: 0.92MB
Bandwidth: 0.01 Mbps