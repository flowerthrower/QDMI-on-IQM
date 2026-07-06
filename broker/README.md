# Device Broker

device broker service, Slurm hook, and client shells.

## Components

- `device-broker-server`
  - `device-brokerd`: loads a configured device library, owns device sessions, and serves broker requests.
  - `device-broker.toml`: configures the daemon socket, device library, symbol prefix, token, and QPU target map.
  - `device-brokerd.service`: runs the daemon on a center-managed service node.
- `device-broker-client`
  - `device-brokerctl`: command-line client used by Slurm hooks to call the daemon.
- `device-broker-slurm`
  - `device-broker-prolog`: asks the daemon to create job allocations.
  - `device-broker-epilog`: asks the daemon to revoke job allocations.
  - `device-broker.conf`: Slurm config example for hook paths.
- Existing runtime integrations
  - `iqm-spank-plugin`: injects broker job environment.
  - `iqm.qdmi.qiskit.IQMBackend`: uses broker job environment instead of direct vendor auth.

## Build

Service node build:

```bash
cmake -S . -B build-device-broker -DBUILD_DEVICE_BROKER=ON
cmake --build build-device-broker --target device-broker --parallel
sudo cmake --install build-device-broker --component device-broker-server
sudo cmake --install build-device-broker --component device-broker-client
```

Slurm install:

```bash
sudo cmake --install build-device-broker --component device-broker-slurm
```
