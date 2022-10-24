import { Component, ViewChild } from '@angular/core';
import { FormControl, Validators } from '@angular/forms';
import { MatGridList } from '@angular/material/grid-list';
import { ElectronService } from 'ngx-electron';

export interface Cell {
  id: number;
  status: 'blank' | 'blocked' | 'visited' | 'objective'
}
@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.sass']
})
export class AppComponent {

  title = 'Grid'
  @ViewChild(MatGridList) grid: MatGridList | undefined

  dimension = 0
  cells: any[] = []

  initialCellId: number | null = null
  finalCellId: number | null = null

  appState: 'grid-generation' | 'objective-selection' | 'barrier-selection' | 'result' = 'grid-generation'

  dimensionCtrl: FormControl = new FormControl(3, [Validators.required, Validators.min(2), Validators.max(10)])

  constructor(
    private electronService: ElectronService
  ) {}

  renderCells(): void {
    this.dimension = this.dimensionCtrl.value
    this.cells = Array(this.dimension**2)
    .fill(0)
    .map((v, i) => ({
      id: i+1,
      status: 'blank'
    }))
    this.initialCellId = null
    this.finalCellId = null
    this.appState = 'objective-selection'
  }


  onCellClick(cell: Cell) {
    let { status } = cell
    
    if(this.appState == 'barrier-selection') {
      if(this.initialCellId == cell.id || this.finalCellId == cell.id) return
      cell.status = status == 'blocked' ? 'blank' : 'blocked'
    }

    if(this.appState == 'objective-selection') {
      cell.status = 'objective'
      if(this.initialCellId == null)
        this.initialCellId = cell.id
      else if(this.initialCellId != cell.id){
        this.finalCellId = cell.id
        this.appState = 'barrier-selection'
      }
    }
  }

  restartGrid() {
    this.initialCellId = null
    this.finalCellId = null
    this.appState = 'objective-selection'
    this.cells = this.cells.map(c => ({ ...c, status: 'blank' }))
  }

  async createPath() {
    if(!this.electronService.isElectronApp) return
    let addonResponse: string = await this.electronService.ipcRenderer.invoke('create-path', this.cells)
    console.log("Response", addonResponse)

    let path: number[] = addonResponse.split(",").map(s => +s) 
    let initialIndex = path.indexOf(this.initialCellId as number)
    if(initialIndex > -1)
      path.splice(initialIndex, 1)
    let finalIndex = path.indexOf(this.finalCellId as number)
    if(finalIndex > -1)
      path.splice(finalIndex, 1)
    this.drawResult(path)
  }

  async drawResult(path: number[]) {
    for (let j = 0; j < path.length; j++) {
      const node = path[j];
      let index = this.cells.findIndex((cell) => node == cell.id)
      if(index > -1) 
        this.cells[index].status = 'visited'
      await new Promise((resolve, reject )=> {
        setTimeout(() => resolve(1), 250)
      })
    }
  }


  get validGrid() { return this.initialCellId !== null && this.finalCellId !== null && this.dimensionCtrl.valid }
}

// TODO: Grid gutter expansion/retractoin animation for loading